#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

/*
1. 연구소 상황 입력
2. 받은 연구소 상황 복사
3. 복사한 곳에서 3개의 벽을 임의로 새움(재귀)
4. 벽을 세운 상태에서 바이러스를 퍼트림
5. 다 퍼뜨린후 안전구역 계산
6. 구역의 수를 기존의 저장값과 비교하여 최대인지 확인
7. 모든 벽을 세울 수 있는 경우의 수를 계산 할때까지 
3~7 과정 반복.
*/

typedef struct
{
	int y, x;
}Dir;

Dir moveDir[4] = { {0,1},{0,-1},{1,0},{-1,0} };

int n, m;
int lab[8][8];
int tmp[8][8];
int ans;

void bfs(void)
{
	int afterSpread[8][8];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			afterSpread[i][j] = tmp[i][j];

	queue <pair<int, int>> q;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			if (afterSpread[i][j] == 2)
				q.push(make_pair(i, j));
	}
	while (!q.empty())
	{
		auto p = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = p.first + moveDir[i].y;
			int nx = p.second + moveDir[i].x;
			if (0 <= ny && ny < n && 0 <= nx && nx < m)
			{
				if (afterSpread[ny][nx] == 0)
				{
					afterSpread[ny][nx] = 2;
					q.push(make_pair(ny, nx));
				}
			}
		}
	}
	int empty = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (afterSpread[i][j] == 0)
				empty++;
	ans = max(ans, empty);
}

void make(int cnt)
{
	if (cnt == 3)
	{
		bfs();
		return;
	}
	for(int i=0;i<n;i++)
		for (int j = 0; j < m; j++)
		{
			if (tmp[i][j] == 0)
			{
				tmp[i][j] = 1;
				make(cnt + 1);
				tmp[i][j] = 0;
			}
		}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> lab[i][j];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (lab[i][j] == 0)
			{
				for (int k = 0; k < n; k++)
					for (int l = 0; l < m; l++)
					{
						tmp[k][l] = lab[k][l];
					}
				tmp[i][j] = 1;
				make(1);
				tmp[i][j] = 0;
			}
		}
	}
	cout << ans << '\n';
}
