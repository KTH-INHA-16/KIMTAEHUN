#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

/*
단순하게 생각해도 풀리는 문제이다.
1. vector<pair<int, pair<int, int>>> graph[MAX][MAX] 벡터를 생성하여 해당 좌표에 {상어의 크기, {속도, 방향}}을 추가하는 방식으로 전처리를 진행합니다.

2. 우선, 낚시꾼이 이동하므로 낚시꾼의 x 좌표를 한 칸 움직여줍니다.

3. 낚시꾼이 이동한 x 좌표를 기준으로 y 좌표를 오름차순으로 탐색하며 상어가 있는지 확인하며 제일 먼저 탐색한 상어를 잡고 반복문을 빠져나옵니다.

4. 상어를 이동하는데, 큐에 상어의 좌표와 {상어의 크기, {속도, 방향}}을 넣어주고 해당 좌표에 있는 상어들을 모두 없애줍니다.

5. 큐에 넣은 상어들을 각각의 속도만큼 이동해주는데 벽에 마주할 경우 적절한 인덱싱을 통해 반대방향으로 돌아 움직일 수 있게 해줍니다.

6. 이동한 좌표에 상어를 추가하는데 해당 칸에 이미 자신보다 큰 상어가 있는 경우에는 추가해주지 않고 자신보다 작은 상어가 있으면 해당 상어를 쫒아내고 해당 칸에 들어갑니다.

7. 낚시꾼이 x 범위를 모두 이동할 동안 3 ~ 6번을 반복합니다.
*/

typedef struct
{
	int speed, dir, size;
}shark;

bool operator<(const shark& a,const shark& b)
{
	if (a.size < b.size)
		return true;
	else
		return false;
}

int r, c, m;
shark map[101][101];
priority_queue<shark> save[101][101];
int ans;

void fish(int x)
{
	shark s = { 0,0,0 };
	for (int i = 1; i <= r; i++)
	{
		if (map[i][x].size != 0)
		{
			ans += map[i][x].size;
			map[i][x] = s;
			break;
		}
	}
}

void move()
{
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			while (!save[i][j].empty())
			{
				save[i][j].pop();
			}
		}
	}
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			if (map[i][j].size > 0)
			{
				int speed = map[i][j].speed;
				int dir = map[i][j].dir;
				int size = map[i][j].size;
				if (map[i][j].dir == 1)
				{
					if (i - 1 >= speed)
					{
						save[i - speed][j].push({ speed,dir,size });
					}
					else
					{
						int product = (speed - i + 1) / (r- 1);
						int remain = (speed - i + 1) % (r - 1);
						if (product % 2 == 0)
						{
							save[1 + remain][j].push({ speed,dir + 1,size });
						}
						else
						{
							save[r- remain][j].push({ speed,dir,size });
						}
					}
				}
				else if (map[i][j].dir == 2)
				{
					if (r - i >= speed)
					{
						save[i + speed][j].push({ speed,dir,size });
					}
					else
					{
						int product = (speed - r + i) / (r - 1);
						int remain = (speed - r + i) % (r - 1);
						if (product % 2 == 0)
						{
							save[r - remain][j].push({ speed,dir - 1,size });
						}
						else
						{
							save[1 + remain][j].push( {speed,dir,size });
						}

					}
				}
				else if (map[i][j].dir == 3)
				{
					if (c - j >= speed)
					{
						save[i][j + speed].push({ speed,dir,size });
					}
					else
					{
						int product = (speed - c + j) / (c - 1);
						int remain = (speed - c + j) % (c - 1);
						if (product % 2 == 0)
						{
							save[i][c - remain].push({ speed,dir + 1,size });
						}
						else
						{
							save[i][1 + remain].push({ speed,dir,size });
						}
					}
				}
				else if (map[i][j].dir == 4)
				{
					if (j - 1 >= speed)
					{
						save[i][j - speed].push({ speed,dir,size });
					}
					else
					{
						int product = (speed - j + 1) / (c - 1);
						int remain = (speed - j + 1) % (c - 1);
						if (product % 2 == 0)
						{
							save[i][1 + remain].push({ speed,dir - 1,size });
						}
						else
						{
							save[i][c - remain].push({ speed,dir,size });
						}
					}
				}
			}
		}
	}
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			if (!save[i][j].empty())
			{
				shark t = { save[i][j].top().speed,save[i][j].top().dir,save[i][j].top().size };
				map[i][j] = t;
			}
			else
			{
				shark t = { 0,0,0 };
				map[i][j] = t;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> r >> c >> m;
	for (int i = 0; i < m; i++)
	{
		int y, x, s, d, z;
		cin >> y >> x >> s >> d >> z;
		map[y][x] = { s,d,z };
	}
	for (int i = 1; i <= c;i++)
	{
		fish(i);
		move();

	}
	cout << ans << '\n';
}