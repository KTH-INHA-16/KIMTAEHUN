#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, ans;
int m[21][21];

void move(int cnt)
{
	queue<int> q;
	//한 열, 행을 몽땅 큐에 넣은다음
	//상황에 맞추어서 구현
	if (cnt == 0)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if(m[i][j])
					q.push(m[i][j]);
				m[i][j] = 0;
			}
			int idx = 0;
			while (!q.empty())
			{
				int d = q.front();
				q.pop();
				if (m[i][idx] == 0)
					m[i][idx] = d;
				else if (m[i][idx]==d)
				{
					m[i][idx] *= 2;
					idx++;
				}
				else
				{
					idx++;
					m[i][idx] = d;
				}
			}
		}
	}
	else if (cnt == 1)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = n-1; j >= 0; j--)
			{
				if (m[i][j])
					q.push(m[i][j]);
				m[i][j] = 0;
			}
			int idx = n-1;
			while (!q.empty())
			{
				int d = q.front();
				q.pop();
				if (m[i][idx] == 0)
					m[i][idx] = d;
				else if (m[i][idx] == d)
				{
					m[i][idx] *= 2;
					idx--;
				}
				else
				{
					idx--;
					m[i][idx] = d;
				}

			}
		}
	}
	else if (cnt == 2)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (m[j][i])
					q.push(m[j][i]);
				m[j][i] = 0;
			}
			int idx = 0;
			while (!q.empty())
			{
				int d = q.front();
				q.pop();
				if (m[idx][i] == 0)
					m[idx][i] = d;
				else if (m[idx][i] == d)
				{
					m[idx][i] *= 2;
					idx++;
				}
				else
				{
					idx++;
					m[idx][i] = d;
				}
			}
		}
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = n-1; j >= 0; j--)
			{
				if (m[j][i])
					q.push(m[j][i]);
				m[j][i] = 0;
			}
			int idx = n-1;
			while (!q.empty())
			{
				int d = q.front();
				q.pop();
				if (m[idx][i] == 0)
					m[idx][i] = d;
				else if (m[idx][i] == d)
				{
					m[idx][i] *= 2;
					idx--;
				}
				else
				{
					idx--;
					m[idx][i] = d;
				}
			}
		}
	}
}

void dfs(int cnt)
{
	if (cnt == 5)
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				ans = max(ans, m[i][j]);
		return;
	}
	int save[21][21];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			save[i][j] = m[i][j];

	for (int i = 0; i < 4; i++)
	{
		move(i);
		dfs(cnt + 1);
		//퇴각검색
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				m[i][j] = save[i][j];
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> m[i][j];
	dfs(0);
	cout << ans << '\n';
}