#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

int a[101][101];
int d[101][101];
int dist[101][101];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int ans = 0;
int n, m;

void bfs(int x, int y)
{
	queue<pair<int, int>>q;
	q.push(make_pair(x, y));
	d[x][y] = 1;
	dist[x][y] = 1;
	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < m)
			{
				if (a[nx][ny] == 1&&d[nx][ny]==0)
				{
					q.push(make_pair(nx, ny));
					dist[nx][ny] = dist[x][y] + 1;
					d[nx][ny] = true;
				}
			}
		}
	}
}

int main(void)
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < m; j++)
		{
			if (s[j] - '0' == 1)
				a[i][j] = 1;
			else
				a[i][j] = 0;
		}
	}

	bfs(0, 0);
	

	cout <<dist[n-1][m-1]<<endl;
}




//queue<int> q;
//check[1] = true; 
//q.push(1);
//while (!q.empty()) {
//	int x = q.front(); q.pop();
//	printf("%d ", x);
//	for (int i = 1; i <= n; i++) {
//		if (a[x][i] == 1 && check[i] == false) {
//			check[i] = true;
//			q.push(i);
//		}
//	}
//}