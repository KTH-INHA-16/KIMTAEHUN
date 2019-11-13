#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;

struct Edge
{
	int to;
	int cost;
	Edge(int to, int cost) : to(to), cost(cost)
	{}
};

vector<Edge> a[100001];
bool check[100001];
int dist[100001];

void bfs(int s)
{
	memset(dist, 0, sizeof(dist));
	memset(check, false, sizeof(check));
	queue<int>q;
	check[s] = true;
	q.push(s);
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int i = 0; i < a[x].size(); i++)
		{
			Edge &e = a[x][i];
			if (check[e.to] == false)
			{
				dist[e.to] = dist[x] + e.cost;
				q.push(e.to);
				check[e.to] = true;
			}
		}
	}
}


int main(void)
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		while (true)
		{
			int y, z;
			cin >> y;
			if (y == -1)
				break;
			cin >> z;
			a[x].push_back(Edge(y, z));
		}
	}
	bfs(1);
	int s = 1;
	for (int i = 2; i <= n; i++)
	{
		if (dist[i] > dist[s])
			s = i;
	}
	bfs(s);
	int ans = dist[1];
	for (int i = 2; i <= n; i++)
	{
		if (ans < dist[i])
			ans = dist[i];
	}

	cout << ans<<endl;
}