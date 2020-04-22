#include <iostream>
#include <algorithm>
using namespace std;

int ans = 0;
int n, m;
int a[501][501];
bool check[501][501];
pair<int, int> d[] = { {1,0},{-1,0},{0,1},{0,-1} };

int dfs(int y, int x, int cnt)
{
	if (cnt == 4)
		return a[y][x];
	int sum = 0;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + d[i].first;
		int nx = x + d[i].second;
		if (0 <= nx && nx < m && 0 <= ny && ny < n&&!check[ny][nx])
		{
			check[ny][nx] = true;
			sum = max(sum, a[y][x] + dfs(ny, nx, cnt + 1));
			check[ny][nx] = false;
		}
	}
	return sum;
}

int mid(int y, int x)
{
	int result = 0;
	if (y - 1 >= 0 && x + 2 < m)
		result = max(result, a[y][x] + a[y][x + 1] + a[y - 1][x + 1] + a[y][x + 2]);
	if(y+1<n&&x+2<m)
		result = max(result, a[y][x] + a[y][x + 1] + a[y + 1][x + 1] + a[y][x + 2]);
	if (y - 2 >= 0 && x + 1 < m)
		result = max(result, a[y][x] + a[y - 1][x] + a[y - 1][x + 1] + a[y - 2][x]);
	if(y-2>=0&&x -1 >= 0)
		result = max(result, a[y][x] + a[y - 1][x] + a[y - 1][x - 1] + a[y - 2][x]);
	return result;
}


int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			check[i][j] = true;
			ans = max(ans, dfs(i, j, 1));
			ans = max(ans, mid(i, j));
			check[i][j] = false;
		}
	cout << ans << '\n';
}