#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m;
int a[9][9];
int save[9][9];
int ans;
bool check[9][9][4];
pair<int, int> d[] = { {0,1},{-1,0},{0,-1},{1,0} };
vector<int> angle;
vector<pair<int, int>> camera;

//그래프 문제이면 dfs나 bfs를 활용할 생각을 하자

void copy()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			save[i][j] = a[i][j];
}

int counting()
{
	int tmp = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (save[i][j] == 0)
				tmp++;
	return tmp;
}

void dfs(int cnt)
{
	if (cnt == camera.size())
	{
		for (int i = 0; i < angle.size(); i++)
		{
			int y = camera[i].first;
			int x = camera[i].second;
			for (int j = 0; j < 4; j++)
			{
				if (check[y][x][j])
				{
					int ny = y + d[(angle[i] + j) % 4].first;
					int nx = x + d[(angle[i] + j) % 4].second;
					while (1)
					{
						if (save[ny][nx] == 6)
							break;
						if (!(0 <= ny && ny < n && 0 <= nx && nx < m))
							break;
						if (save[ny][nx] == 0)
							save[ny][nx] = -1;
						ny += d[(angle[i] + j) % 4].first;
						nx += d[(angle[i] + j) % 4].second;
					}
				}
			}
		}
		ans = min(ans,counting());
		copy();
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		angle.push_back(i);
		dfs(cnt + 1);
		angle.pop_back();
	}
}


int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
			if (1 <= a[i][j] && a[i][j] <= 5)
				camera.push_back(make_pair(i, j));
			if (a[i][j] == 1)
				check[i][j][0] = true;
			else if (a[i][j] == 2)
			{
				check[i][j][0] = true; check[i][j][2] = true;
			}
			else if (a[i][j] == 3)
			{
				check[i][j][0] = true; check[i][j][1] = true;
			}
			else if(a[i][j]==4)
			{
				check[i][j][0] = true; check[i][j][1] = true;
				check[i][j][2] =  true;
			}
			else if(a[i][j]==5)
			{
				check[i][j][0] = true; check[i][j][1] = true;
				check[i][j][2] = true;
				check[i][j][3] = true;
			}
		}
	ans = 987654321;
	copy();
	dfs(0);
	cout << ans << '\n';
}