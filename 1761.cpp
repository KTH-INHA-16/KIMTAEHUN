#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <cstring>
using namespace std;

vector <pair<int, int>> a[40001];
int depth[40001];
bool check[40001];
int parent[40001];
int dist[40001];
long long ans;

long long LCA(int a,int b)
{
	ans = 0;
	if (depth[a] > depth[b])
		swap(a, b);
	while (depth[a] != depth[b])
	{
		ans += (dist[b]-dist[parent[b]]);
		b = parent[b];
	}
	while (a != b)
	{
		ans += (dist[a] - dist[parent[a]]);
		ans += (dist[b] - dist[parent[b]]);
		a = parent[a];
		b = parent[b];
	}
	return ans;
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
		int t1, t2, t3;
		cin >> t1 >> t2 >> t3;
		a[t1].push_back(make_pair(t2, t3));
		a[t2].push_back(make_pair(t1, t3));
	}
	depth[1] = 0;
	check[1] = true;
	parent[1] = 0;
	dist[1] = 0;
	queue<int> q;
	q.push(1);
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (auto p : a[x])
		{
			int y = p.first;
			int cost = p.second;
			if (check[y] == false)
			{
				check[y] = true;
				depth[y] = depth[x] + 1;
				parent[y] = x;
				dist[y] = dist[x] + cost;
				q.push(y);
			}
		}
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int t1, t2;
		cin >> t1 >> t2;
		cout << LCA(t1, t2) << '\n';
	}

}