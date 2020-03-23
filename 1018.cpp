#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string c[51];
string a[8] = 
{
		{ "WBWBWBWB" },
		{ "BWBWBWBW" },
		{ "WBWBWBWB" },
		{ "BWBWBWBW" },
		{ "WBWBWBWB" },
		{ "BWBWBWBW" },
		{ "WBWBWBWB" },
		{ "BWBWBWBW" }
};
//8 8 체스판을 먼저 만듬 2가지 버전 시작이 W or B
string b[8] = 
{
		{ "BWBWBWBW" },
		{ "WBWBWBWB" },
		{ "BWBWBWBW" },
		{ "WBWBWBWB" },
		{ "BWBWBWBW" },
		{ "WBWBWBWB" },
		{ "BWBWBWBW" },
		{ "WBWBWBWB" }
};

int white(int y, int x)
{
	int cnt = 0;
	for (int i = y; i < y + 8; i++)
	{
		for (int j = x; j < x + 8; j++)
		{
			if (c[i][j] != a[i - y][j - x])
				cnt += 1;
		}
	}
	return cnt;
}

int black(int y, int x)
{
	int cnt = 0;
	for (int i = y; i < y + 8; i++)
	{
		for (int j = x; j < x + 8; j++)
		{
			if (c[i][j] != b[i - y][j - x])
				cnt += 1;
		}
	}
	return cnt;
}
//w or b 의 체스 판 크기 8 8에서 검사 
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> c[i];

	}
	int ans = 987654321;
	for (int i = 0; i + 7 < n ; i++)
	{
		for (int j = 0; j + 7 < m; j++)
			//i,j는 8 8의 칸을 또 남겨 놓아야함
		{
			ans = min(ans, min(white(i, j), black(i, j)));
		}
	}
	cout << ans << '\n';

}