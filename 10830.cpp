#include <iostream>
#include <cstring>
using namespace std;
long long n;
long long b;
long long a[6][6];
long long c[6][6];
long long ans[6][6];

void cal(long long a[6][6], long long b[6][6])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			c[i][j] = 0;
			for (int k = 0; k < n; k++)
			{
				c[i][j] += a[i][k] * b[k][j];
			}
			c[i][j] %= 1000;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = c[i][j];
		}
	}
}

int main()
{
	cin >> n >> b;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
		ans[i][i] = 1;
	}
	while (b > 0)
	{
		if (b % 2 == 1)
			cal(ans, a);
		cal(a, a);
		b /= 2;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << ans[i][j] << ' ';
		cout << '\n';
	}
	
}