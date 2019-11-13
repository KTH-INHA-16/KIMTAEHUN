#pragma warning(disable:4996)
#include <iostream>
#include <queue>
#include <deque>
#include <cstring>
using namespace std;
int n, m;
int a[555][555];
int cnt[555][555];
int dx[] = {0,0,1,-1 };
int dy[] = { 1,-1,0,0};

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%1d", &a[i][j]);
			cnt[i][j] = -1;
		}
	}
	cnt[0][0] = 0;
	queue<pair<int, int>> q;
	queue < pair<int, int>>next;
	q.push(make_pair(0, 0));
	while (!q.empty())
	{
		auto p = q.front();
		int x = p.first;
		int y = p.second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < m&&ny >= 0 && ny < n)
			{
				if (cnt[nx][ny] == -1)
				{
					if (a[nx][ny] == 0)
					{
						cnt[nx][ny] = cnt[x][y];
						q.push(make_pair(nx, ny));
					}
					else
					{
						cnt[nx][ny] = cnt[x][y] + 1;
						next.push(make_pair(nx, ny));
					}
				}
			}
		}
		if (q.empty())
		{
			q = next;
			next = queue<pair<int, int>>();
		}
	}
	//for (int i = 0; i < m; i++)
	//{
	//	for (int j = 0; j < n; j++)
	//	{
	//		cout << cnt[i][j] << ' ';
	//	}
	//	cout << '\n';
	//}
	cout << cnt[m-1][n-1] << '\n';
}