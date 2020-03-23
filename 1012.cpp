#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int a[51][51];
bool check[51][51];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int m, n, k;

void bfs(int x, int y)
{
	queue<pair<int,int>> q;
	q.push(make_pair(y, x));
	check[y][x] = true;
	while (!q.empty())
	{
		auto p = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = dx[i] + p.second;
			int ny = dy[i] + p.first;
			if (nx >= 0 && nx < m&&ny >= 0 && ny < n)
			{
				if (check[ny][nx] == false&&a[ny][nx]==1)
				{
					q.push(make_pair(ny, nx));
					check[ny][nx] = true;
				}
			}
		}
	}
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		memset(a, 0, sizeof(a));
		memset(check, false, sizeof(check));
		cin >> m >> n >> k;
		for (int i = 0; i < k; i++)
		{
			int x, y;
			cin >> x >> y;
			a[y][x] = 1;
		}
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (a[i][j] == 1 && check[i][j] == false)
				{
					bfs(j,i);
					ans += 1;
				}
			}
		}
		cout << ans << '\n';
	}
}