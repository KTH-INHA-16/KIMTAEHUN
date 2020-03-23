#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

/*
1. ������ ��Ȳ �Է�
2. ���� ������ ��Ȳ ����
3. ������ ������ 3���� ���� ���Ƿ� ����(���)
4. ���� ���� ���¿��� ���̷����� ��Ʈ��
5. �� �۶߸��� �������� ���
6. ������ ���� ������ ���尪�� ���Ͽ� �ִ����� Ȯ��
7. ��� ���� ���� �� �ִ� ����� ���� ��� �Ҷ����� 
3~7 ���� �ݺ�.
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
