#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <set>
using namespace std;

vector <int> a[100111];
int depth[100111];
bool check[100111];
int parent[100111];
int p[100111][18];

int lca(int u, int v)
{
	if (depth[u] < depth[v])
		swap(u, v);
	int log = 1;
	for (log = 1; (1 << log) <= depth[u]; log++);
	//u의 높이보다 작을때까지 2^n을 해준다
	log -= 1;
	//2^n-1을 만들어주기 위함
	for (int i = log; i >= 0; i--)
	{
		if (depth[u] - (1 << i) >= depth[v])
		{
			//u의 높이에서 2^n을 빼준 값이 v의 높이보다 클때 
			//u를 u의 2^n번째 부모로 이동시킨다.
			u = p[u][i];
		}
	}
	if (u == v)
		return ;
	//같은 서브트리내에 존재할때
	//같은 높이에 같은 경우는 같은 서브트리 일수 밖에 없다
	else
		//만약 u!=v일 경우
	{
		for (int i = log; i >= 0; i--)
		{
			if (p[u][i] != 0 && p[u][i] != p[v][i])
				//u와 v를 2^n번 이동시킬때 같지 않을때 까지 이동하고
				//u를 2^n번 이동시켰을때 1이 되지않도록 이동
			{
				u = p[u][i];
				v = p[v][i];
			}
		}
		return parent[u];
		//최종적으로 u의 부모 반환 = 공통 조상 반환
		//같은 서브트리내가 아닐때
	}
}

int main()
{
	ios::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int t1, t2;
		cin >> t1 >> t2;
		a[t1].push_back(t2);
		a[t2].push_back(t1);
	}
	check[1] = true;
	depth[1] = 0;
	parent[1] = 0;
	queue<int> q;
	q.push(1);
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int p : a[x])
		{
			int y = p;
			if (check[y] == false)
			{
				check[y] = true;
				depth[y] = depth[x] + 1;
				parent[y] = x;
				q.push(y);
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		p[i][0] = parent[i];
	}
	for (int j = 1; (1 << j) < n; j++)
	{
		for (int i = 1; i <= n; i++)
		{
			if (p[i][j - 1] != 0)
				p[i][j] = p[p[i][j - 1]][j - 1];
		}
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int t1, t2;
		cin >> t1 >> t2;
		cout << lca(t1, t2) << '\n';
	}
}