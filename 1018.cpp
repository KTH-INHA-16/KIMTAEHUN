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
//8 8 ü������ ���� ���� 2���� ���� ������ W or B
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
//w or b �� ü�� �� ũ�� 8 8���� �˻� 
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
			//i,j�� 8 8�� ĭ�� �� ���� ���ƾ���
		{
			ans = min(ans, min(white(i, j), black(i, j)));
		}
	}
	cout << ans << '\n';

}