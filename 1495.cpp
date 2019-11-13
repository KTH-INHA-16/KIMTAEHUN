#include <iostream>
#include <cstring>
using namespace std;

int a[101];
bool d[101][1050];
int n, s, m;

int main()
{
	cin >> n >> s >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	d[0][s] = true;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			if (d[i][j])
			{
				if (j + a[i + 1] <= m)
					d[i + 1][j + a[i + 1]] = true;
				if (j - a[i + 1] >= 0)
					d[i + 1][j - a[i + 1]] = true;
			}
		}
	}
	int ans = -1;
	for (int i = 0; i <=m; i++)
	{
		if (d[n][i] == true)
			ans = i;
	}
	cout << ans << '\n';
}