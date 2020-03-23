#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int a[301][301];
int d[301][301];
int dx[] = { 1,2,1,2,-1,-2,-1,-2 };
int dy[] = { 2,1,-2,-1,2,1,-2,-1 };

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		memset(a, 0, sizeof(a));
		memset(d, 0, sizeof(d));
		int l;
		cin >> l;
		int x, y;
		cin >> x >> y;
		queue<pair<int, int>> q;
		a[y][x] = 1;
		d[y][x] = 1;
		q.push(make_pair(x, y));
		cin >> x >> y;
		while (!q.empty())
		{
			auto p = q.front();
			q.pop();
			for (int i = 0; i < 8; i++)
			{
				int nx = p.first + dx[i];
				int ny = p.second + dy[i];
				if (nx >= 0 && nx < l&&ny >= 0 && ny < l)
				{
					if (a[ny][nx] == 0)
					{
						a[ny][nx] = 1;
						d[ny][nx] = d[p.second][p.first] + 1;
						q.push(make_pair(nx, ny));
					}
				}
			}
		}
		cout << d[y][x] - 1 << '\n';
	}
}