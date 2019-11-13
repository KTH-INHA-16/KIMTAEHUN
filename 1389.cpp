#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int dist[101][101];
int v[101][101];
int inf = 100000000;

int main()
{
	fill(&v[0][0], &v[101][101], -1);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			dist[i][j] = i == j ? 0 : inf;
		}
	}
	for (int i = 0; i < m; i++)
	{
		int t1, t2;
		cin >> t1 >> t2;
		dist[t1][t2] = 1;
		dist[t2][t1] = 1;
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
					v[i][j] = k;
				}
			}
		}
	}
	int ans;
	int min = inf;
	int k;
	for (int i = 1; i <= n; i++)
	{
		ans = 0;
		for (int j = 1; j <= n; j++)
		{
			ans += dist[i][j];
		}
		if (ans < min)
		{
			k = i;
			min = ans;
		}
	}
	cout << k << '\n';

}