#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>
using namespace std;

vector<pair<int, int>> a[100111];
int path[100111];
bool check[100111];
int depth[100111];
int parent[100111];
int p[100111][18];
int len_max[100111][18];
int len_min[100111][18];

pair<int,int> lca(int u, int v)
{
	if (depth[u] < depth[v])
		swap(u, v);
	int log;
	int ans_min = 10000000;
	int ans_max = 0;
	for (log = 1; (1 << log) <= depth[u]; log++);
	log -= 1;
	for (int i = log; i >= 0; i--)
	{
		if (depth[u] - (1 << i) >= depth[v])
		{
			if (ans_min > len_min[u][i])
				ans_min = len_min[u][i];
			if (ans_max < len_max[u][i])
				ans_max = len_max[u][i];
			//비교
			u = p[u][i];
		}
	}
	if (u == v)
		return make_pair(ans_min,ans_max);
	else
	{
		for (int i = log; i >= 0; i--)
		{
			if (p[u][i] != 0 && p[u][i] != p[v][i])
			{
				if (ans_min > len_min[u][i]) 
					ans_min = len_min[u][i];
				if (ans_max < len_max[u][i]) 
					ans_max = len_max[u][i];
				if (ans_min > len_min[v][i]) 
					ans_min = len_min[v][i];
				if (ans_max < len_max[v][i])
					ans_max = len_max[v][i];
				//비교
				u = p[u][i];
				v = p[v][i];
				
			}
		}
		if (ans_min > len_min[u][0])
			ans_min = len_min[u][0];
		if (ans_max < len_max[u][0])
			ans_max = len_max[u][0];
		if (ans_min > len_min[v][0])
			ans_min = len_min[v][0];
		if (ans_max < len_max[v][0])
			ans_max = len_max[v][0];
		//한번더 비교
		return make_pair(ans_min,ans_max);
	}

}

int main()
{
	ios::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n;
	for (int i = 0; i < n-1; i++)
	{
		int t1, t2, t3;
		cin >> t1 >> t2 >> t3;
		a[t1].push_back(make_pair(t2, t3));
		a[t2].push_back(make_pair(t1, t3));
	}
	check[1] = true;
	depth[1] = 0;
	queue<int> q;
	q.push(1);
	parent[1] = 0;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (auto p : a[x])
		{
			int y = p.first;
			int cost = p.second;
			if (check[y]==false)
			{
				check[y] = true;
				parent[y] = x;
				path[y] = cost;
				depth[y] = depth[x] + 1;
				q.push(y);
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		p[i][0] = parent[i];
		len_max[i][0] = path[i];
		len_min[i][0] = path[i];
	}
	for (int j = 1; (1 << j) < n; j++)
	{
		for (int i = 1; i <= n; i++)
		{
			if (p[i][j - 1] != 0)
			{
				p[i][j] = p[p[i][j - 1]][j - 1];
				len_min[i][j] = len_min[i][j - 1];
				len_max[i][j] = len_max[i][j - 1];
				//최대와 최소를 채워줌
				if (p[p[i][j - 1]][j - 1] != 0)
					//이전 노드의 j-1이 0이 아니면
				{
					len_min[i][j] = min(len_min[i][j - 1], len_min[p[i][j - 1]][j - 1]);
					len_max[i][j] = max(len_max[i][j - 1], len_max[p[i][j - 1]][j - 1]);
					//최대값과 최소값을 갱신
				}
			}
		}
	}
	cin >> m;
	while (m--)
	{
		int t1, t2;
		cin >> t1 >> t2;
		auto p = lca(t1, t2);
		printf("%d %d\n", p.first, p.second);
	}

}