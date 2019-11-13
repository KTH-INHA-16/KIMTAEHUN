#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
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

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int x,y,z;
		cin >> x >> y >> z;
		a[x].push_back(Edge(y,z));
		//1167번이랑 다르게 이문제는 양방향 노드와 길이를 추가해줘야함
		a[y].push_back(Edge(x, z));
	}
	int s = 1;
	bfs(1);
	for (int i = 2; i <= n; i++)
	{
		if (dist[s] < dist[i])
			s = i;
	}
	bfs(s);
	int ans = dist[1];
	for (int i = 2; i <= n; i++)
	{
		if (ans < dist[i])
			ans = dist[i];
	}
	

	cout << ans << endl;
}