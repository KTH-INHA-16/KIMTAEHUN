#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int dist[401][401];
int inf = 10000000;

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			dist[i][j] = inf;
		}
	}
	for (int i = 0; i < m; i++)
	{
		int t1, t2, t3;
		cin >> t1 >> t2 >> t3;
		dist[t1][t2] = dist[t1][t2]>t3?t3:dist[t1][t2];
	}
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (dist[i][j] > dist[i][k] + dist[k][j])
				{
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
	int ans = inf;
	for (int i = 1; i <= n; i++)
	{
		if (ans > dist[i][i])
			ans = dist[i][i];
	}
	if (ans == inf)
		cout << "-1" << '\n';
	else
		cout << ans << '\n';
}