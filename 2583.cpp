#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int a[101][101];
bool check[101][101];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int m, n, k;
int ans;
vector <int> result;

int bfs(int y, int x)
{
	check[y][x] = true;
	int tmp = 1;
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	while (!q.empty())
	{
		auto p = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = dy[i] + p.second;
			int nx = dx[i] + p.first;
			if (nx >= 0 && nx < n && ny >= 0 && ny < m)
			{
				if (a[ny][nx] == 0&&check[ny][nx]==false)
				{
					tmp += 1;
					check[ny][nx] = true;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	return tmp;
}

int main()
{
	cin >> m >> n >> k;
	for (int i = 0; i < k; i++)
	{
		int x1, y1,x2,y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int j = y1; j < y2; j++)
			for (int k = x1; k < x2; k++)
				a[j][k] = 1;
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] == 0&&check[i][j]==false)
			{
				ans += 1;
				result.push_back(bfs(i, j));
			}
		}
	}
	sort(result.begin(), result.end());
	cout << ans << '\n';
	for (int i = 0 ; i < result.size(); i++)
		cout << result[i] << '\n';
}