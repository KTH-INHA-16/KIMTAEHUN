#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

long long d[1001][1001];

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i <= n; i++)
	{
		d[i][0] = d[i][i] = 1;
		for (int j = 1; j <= i - 1; j++)
		{
			d[i][j] = d[i - 1][j - 1] + d[i - 1][j];
			d[i][j] %= 10007;
		}
	}
	cout << d[n][m] << '\n';
}