#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <tuple>
using namespace std;

int a[1000][1000];
int d[1000][1000][2];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%1d", &a[i][j]);
		}
	}
	queue<tuple<int, int, int>> q;
	d[0][0][0] = 1;
	q.push(make_tuple(0, 0, 0));
	while (!q.empty())
	{
		int x, y, z;
		tie(x, y, z) = q.front(); q.pop();
		for (int k = 0; k < 4; k++)
		{
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			if (a[nx][ny] == 0 && d[nx][ny][z] == 0)
				//해당 좌표가 0인 경우
			{
				d[nx][ny][z] = d[x][y][z] + 1;
				q.push(make_tuple(nx, ny, z));
			}
			if (z == 0 && a[nx][ny] == 1 && d[nx][ny][z + 1] == 0)
				//벽을 0번 부수고 해당 좌표가 1이고
				// z+1의 좌표가 0으로 미입력 경우
			{
				d[nx][ny][z + 1] = d[x][y][z] + 1;
				q.push(make_tuple(nx, ny, z + 1));
			}
		}
	}
	if (d[n - 1][m - 1][0] != 0 && d[n - 1][m - 1][1] != 0)
		//한번 부수고 + 안부수고 최종 점에 도달할때
	{
		cout << min(d[n - 1][m - 1][0], d[n - 1][m - 1][1]);
	}
	else if (d[n - 1][m - 1][0] != 0)
		//부셔야지만 가능할때
	{
		cout << d[n - 1][m - 1][0];
	}
	else if (d[n - 1][m - 1][1] != 0)
		//안부시고 가능한 경우
	{
		cout << d[n - 1][m - 1][1];
	}
	else
	{
		cout << -1;
	}
	cout << '\n';
	return 0;
}