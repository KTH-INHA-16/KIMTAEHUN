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
	//���� �������� �����°��� ����
	if (d[i][j] != -1)
		return d[i][j];
	int &ans = d[i][j];
	for (int k = i; k <= j; k++)
	{
		int tmp = go(i, k) + go(k + 1, j) + s[j] - s[i - 1];
		// i~k + k+1~j������ ������ �� + �� ������ ��
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
			//1������ ���� n���������� ��� ���� ����
		}
		cout<<go(1, k)<<'\n';
	}
}