#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
using namespace std;

int map[201][201];
int n, m;
int parent[201];
int cnt;

void union_find(int a, int b)
{
	parent[b] = a;
}

int parent_find(int b)
{
	if (parent[b] == b)
		return parent[b];
	else
		return parent_find(parent[b]);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	vector<int> road(m);
	for (int i = 1; i <= n; i++)
		parent[i] = i;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			cin >> map[i][j];
			if (map[i][j] != 0)
			{
				int a = parent_find(i);
				int b = parent_find(j);
				if (a < b)
					union_find(a, b);
				else
					union_find(b, a);
			}
		}
	for (int i = 0; i < m; i++)
		cin >> road[i];
	cnt = parent_find(road[0]);
	for (int i = 1; i < m; i++)
	{
		if (cnt != parent_find(road[i]))
		{
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
}