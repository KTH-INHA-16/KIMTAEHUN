#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <math.h>
#include <set>
using namespace std;

/*
bfs/dfs를 이용한 풀이 자체 까지는 맞았으나
내가 짠 코드는 결정적으로 바꾼것만을 바꿔야하는데
국경이 이어지지도 않은곳을 바꿔버리는 치명적인 잘못을 
저질렀다.......
*/

typedef pair<int, int> pii;

int n, l, r;
bool visit[51][51];
int a[51][51];
pii dir[] = { {0,1},{1,0},{0,-1},{-1,0} };
vector<pii> v;
int p, s;
int ans;

void dfs(int y, int x)
{
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dir[i].first;
		int ny = y + dir[i].second;
		int dif = abs(a[ny][nx] - a[y][x]);
		if (0 <= nx && nx < n && 0 <= ny && ny < n)
		{
			if (l <= dif && dif <= r && !visit[ny][nx])
			{
				visit[ny][nx] = true;
				p += a[ny][nx];
				v.push_back(pii(ny, nx));
				s++;
				dfs(ny, nx);
			}
		}
	}
}

bool solve()
{
	bool found = false;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (visit[i][j])
				continue;
			visit[i][j] = true;
			p = a[i][j];
			s = 1;
			v.clear();
			v.push_back(pii(i, j));
			dfs(i, j);
			if (s >= 2)
			{
				found = true;
				for (int i = 0; i < v.size(); i++)
					a[v[i].first][v[i].second] = p / s;
			}
		}
	}
	if (found)
		ans++;
	return found;
}

int main()
{
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	while (true)
	{
		memset(visit, false, sizeof(visit));
		if (!solve())
		{
			cout << ans << '\n';
			return 0;
		}
	}
}