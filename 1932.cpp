#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a[501][501];
long long m[501][501];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= i; j++)
			cin >> a[i][j];
	m[0][0] = a[0][0];
	for (int i = 1; i < n; i++)
	{
		m[i][0] = m[i - 1][0] + a[i][0];
		m[i][i] = m[i - 1][i - 1] + a[i][i];
	}
	for (int i = 2; i < n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (m[i][j] == 0)
			{
				m[i][j] = max(m[i - 1][j], m[i - 1][j - 1]) + a[i][j];
			}
		}
	}

	long long ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (ans < m[n - 1][i])
			ans = m[n - 1][i];
	}
	cout << ans << '\n';
}