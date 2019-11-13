#include <iostream>
#include <queue>
using namespace std;

int a[100][100];
int d[100][100];
int g[100][100];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int n;

void dfs(int x, int y, int cnt)
{
	g[x][y] = cnt;
	for (int k = 0; k < 4; k++)
	{
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (0 <= nx && nx < n &&
			0 <= ny && ny < n)
		{
			if (a[nx][ny] == 1
				&& g[nx][ny] == 0)
			{
				dfs(nx, ny, cnt);
			}
		}
	}
}

int main(void)
{
	queue <pair<int, int>>q;
	queue <pair<int, int>>q2;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == 1)
			{
				d[i][j] = 1;
				q.push(make_pair(i, j));
				q2.push(make_pair(i, j));
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] == 1 && g[i][j] == 0)
				dfs(i, j, ++cnt);
		}
	}

	while (!q2.empty()) {
		int x = q2.front().first;
		int y = q2.front().second;
		q2.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				if (a[nx][ny] == 0 && g[nx][ny] == 0) {
					g[nx][ny] = g[x][y];
					q2.push(make_pair(nx, ny));
				}
			}
		}
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				if (a[nx][ny] == 0 && d[nx][ny] == 0) {
					d[nx][ny] = d[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}

	int ans = 10000;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				int ni = i + dx[k];
				int nj = j + dy[k];
				if (0 <= ni && ni < n && 0 <= nj && nj < n)
				{
					if (g[i][j] != g[ni][nj])
						if (ans > (d[i][j] + d[ni][nj] - 2))
							ans = d[i][j] + d[ni][nj] - 2;
					
				}
			}
		}
	}

	printf("%d\n", ans);
}