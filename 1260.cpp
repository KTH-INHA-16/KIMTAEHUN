#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> p[1001];
bool check[1001];

void dfs(int x)
{
	check[x] = true;
	printf("%d ", x);
	for (int i = 0; i < p[x].size(); i++)
	{
		int y = p[x][i];
		if (check[y] == false)
			dfs(y);
	}
}

void bfs(int x)
{
	queue<int> q;
	memset(check, false, sizeof(check));
	check[x] = true;
	q.push(x);
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		printf("%d ", x);
		for (int i = 0; i < p[x].size(); i++)
		{
			int y = p[x][i];
			if (check[y] == false)
			{
				check[y] = true;
				q.push(y);
			}
		}
	}

}

int main()
{
	int n,m,v;
	cin >> n>>m>> v;
 	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		p[a].push_back(b);
		p[b].push_back(a);
	}

	for (int i = 1; i < n; i++)
	{
		sort(p[i].begin(), p[i].end());
	}
	
	dfs(v);
	printf("\n");
	bfs(v);
	printf("\n");
}