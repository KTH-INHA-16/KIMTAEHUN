#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int a[501];
int s[501];
int d[501][501];

int go(int i, int j)
{
	if (i == j)
		return 0;
	//같은 페이지가 나오는것을 방지
	if (d[i][j] != -1)
		return d[i][j];
	int &ans = d[i][j];
	for (int k = i; k <= j; k++)
	{
		int tmp = go(i, k) + go(k + 1, j) + s[j] - s[i - 1];
		// i~k + k+1~j까지의 페이지 합 + 총 페이지 합
		if (ans == -1 || ans > tmp)
			ans = tmp;
	}
	return ans;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		memset(s, 0, sizeof(s));
		memset(d, -1, sizeof(d));
		int k;
		cin >> k;
		for (int i = 1; i <= k; i++)
		{
			cin >> a[i];
			s[i] = s[i - 1] + a[i];
			//1페이지 부터 n페이지까지 모두 더한 총합
		}
		cout<<go(1, k)<<'\n';
	}
}