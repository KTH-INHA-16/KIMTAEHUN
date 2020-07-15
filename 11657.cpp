#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int m, n;
vector<pair<int,int>> map[501];
const long long inf = 1e18;

int main()
{
	cin >> n >> m;
	long long dist[501];
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		map[a - 1].push_back({ b - 1,c });
	}
	bool cycle = false;
	fill(dist, dist + n, inf);
	dist[0] = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < map[j].size(); k++)
			{
				int next = map[j][k].first;
				int next_d = map[j][k].second;
				if (dist[j] != inf && dist[next] > dist[j] + next_d)
				{
					dist[next] = dist[j] + next_d;
					if (i == n - 1)
						cycle = true;
				}
			}
		}
	}
	if (cycle)
		cout << -1 << '\n';
	else
	{
		for (int i = 1; i < n; i++)
		{
			cout << (dist[i] != inf ? dist[i] : -1) << '\n';
		}
	}
}