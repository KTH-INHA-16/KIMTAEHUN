#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int a[1001][1001];
int d[1001][1001];
int b[1001][1001];
bool cnt[1001][1001];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int n, m;

int main()
{
	
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%1d", &a[i][j]);
			d[i][j] = -1;
		}
	}
	d[0][0] = 1;
	cnt[0][0] = true;
	queue<pair<int, pair<int, int>>> q;
	queue<pair<int, pair<int, int>>> next;
	q.push(make_pair(0, make_pair(0, 0)));
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second.first;
		int c = q.front().second.second;
		q.pop();
		for (int k = 0; k < 4; k++)
		{
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			if (cnt[nx][ny]==false)
			{
				if (a[nx][ny] == 0)
				{
					cnt[nx][ny] = true;
					if (d[nx][ny] == -1)
						d[nx][ny] = d[x][y] + 1;
					else
						d[nx][ny] = min(d[x][y] + 1, d[nx][ny]);
					q.push(make_pair(nx, make_pair(ny, c)));
				}
				else if(a[nx][ny]==1)
				{
					if (c == 0)
					{
						cnt[nx][ny] = true;
						if (d[nx][ny] == -1)
							d[nx][ny] = d[x][y] + 1;
						else
							d[nx][ny] = min(d[x][y] + 1, d[nx][ny]);
						next.push(make_pair(nx, make_pair(ny, c + 1)));
					}
				}
			}
		}
		if (q.empty())
		{
			q = next;
			next = queue < pair<int, pair<int, int>>>();
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << d[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << d[n - 1][m - 1] << '\n';
}