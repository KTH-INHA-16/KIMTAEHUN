#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int a[501][501];
long long d[501][501];//10억이상
int n, m;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

long long go(int x, int y)
//전형적인 dfs문제 사이클 성립 안됨
{
	if (x == n-1 && y == m-1)
		return 1;
	if (d[x][y]!=-1)
		return d[x][y];
	long long &ans = d[x][y];//값을 저장하기 위해(계속 저장 하기 위함)
	ans = 0;//초깃값->경로 수
	for (int k = 0; k < 4; k++)
	{
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (0 <= nx && nx < n && 0 <= ny && ny < m)
		{
			if (a[x][y] > a[nx][ny])
				ans += go(nx, ny);
		}
	}
	return ans;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			scanf("%d", &a[i][j]);
	}
	memset(d, -1, sizeof(d));
	printf("%lld\n",go(0,0));
}