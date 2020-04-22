#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

/*
�ܼ��ϰ� �����ص� Ǯ���� �����̴�.
1. vector<pair<int, pair<int, int>>> graph[MAX][MAX] ���͸� �����Ͽ� �ش� ��ǥ�� {����� ũ��, {�ӵ�, ����}}�� �߰��ϴ� ������� ��ó���� �����մϴ�.

2. �켱, ���ò��� �̵��ϹǷ� ���ò��� x ��ǥ�� �� ĭ �������ݴϴ�.

3. ���ò��� �̵��� x ��ǥ�� �������� y ��ǥ�� ������������ Ž���ϸ� �� �ִ��� Ȯ���ϸ� ���� ���� Ž���� �� ��� �ݺ����� �������ɴϴ�.

4. �� �̵��ϴµ�, ť�� ����� ��ǥ�� {����� ũ��, {�ӵ�, ����}}�� �־��ְ� �ش� ��ǥ�� �ִ� ������ ��� �����ݴϴ�.

5. ť�� ���� ������ ������ �ӵ���ŭ �̵����ִµ� ���� ������ ��� ������ �ε����� ���� �ݴ�������� ���� ������ �� �ְ� ���ݴϴ�.

6. �̵��� ��ǥ�� �� �߰��ϴµ� �ش� ĭ�� �̹� �ڽź��� ū �� �ִ� ��쿡�� �߰������� �ʰ� �ڽź��� ���� �� ������ �ش� �� �i�Ƴ��� �ش� ĭ�� ���ϴ�.

7. ���ò��� x ������ ��� �̵��� ���� 3 ~ 6���� �ݺ��մϴ�.
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