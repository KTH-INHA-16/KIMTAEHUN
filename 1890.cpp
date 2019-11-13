#include <iostream>
#include <cstdio>
using namespace std;

int a[101][101];
long long d[101][101];
int n;


int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];
	d[1][1] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (a[i][j] == 0)
				continue;
			if (i + a[i][j] <= n)
				d[i + a[i][j]][j] += d[i][j];
			if (j + a[i][j] <= n)
				d[i][j + a[i][j]] += d[i][j];
		}
	}
	cout << d[n][n]<<'\n';
}