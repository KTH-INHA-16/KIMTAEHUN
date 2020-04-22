#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <deque>
using namespace std;

typedef pair<int, int> pii;
int up, down;
int r, c, t;
deque<int> map[51];
pii dir[] = { {1,0},{0,1},{-1,0},{0,-1} };

void spread()
{
	int save[51][51] = {0,};
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			int cnt = 0;
			if (map[i][j]>0)
			{
				for (int k = 0; k < 4; k++)
				{
					int ny = i + dir[k].first;
					int nx = j + dir[k].second;
					if (0 <= nx && nx < c && 0 <= ny && ny < r)
					{
						if (map[ny][nx] != -1)
						{
							save[ny][nx] += (map[i][j] / 5);
							cnt++;
						}
					}
				}
				save[i][j] -= (map[i][j] / 5) * cnt;
			}
		}
	}

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (map[i][j] != -1)
			{
				if (map[i][j] + save[i][j] >= 0)
					map[i][j] += save[i][j];
				else
					map[i][j] = 0;
			}
		}
	}
}

void up_wind()
{
	for (int i = up-1; i >= 1; i--)
		map[i][0] = map[i - 1][0];
	map[0].pop_front();
	map[0].push_back(map[1][c - 1]);
	for (int i = 1; i <= up - 1; i++)
		map[i][c - 1] = map[i + 1][c - 1];
	map[up].pop_back();
	map[up].pop_front();
	map[up].push_front(0);
	map[up].push_front(-1);
}

void down_wind()
{
	for (int i = down+1; i <= r - 2; i++)
		map[i][0] = map[i + 1][0];
	map[r-1].pop_front();
	map[r-1].push_back(map[r-2][c - 1]);
	for (int i = r - 2; i >= down + 1; i--)
		map[i][c - 1] = map[i - 1][c - 1];
	map[down].pop_back();
	map[down].pop_front();
	map[down].push_front(0);
	map[down].push_front(-1);
}

int main()
{
	cin >> r >> c >> t;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
		{
			int x;
			cin >> x;
			map[i].push_back(x);
			if (map[i][j] == -1)
			{
				if (up == 0)
					up = i;
				else
					down = i;
			}
		}
	for (int i = 0; i < t; i++)
	{
		spread();
		up_wind();
		down_wind();
	}
	int ans = 0;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (map[i][j] > 0)
				ans += map[i][j];
		}
	}
	cout << ans << '\n';
}