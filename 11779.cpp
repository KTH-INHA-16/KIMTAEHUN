#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Edge
{
public:
	int to;
	int cost;
	Edge(int to, int cost) :to(to), cost(cost)
	{
	}
};
vector<Edge> a[1001];
int dist[1001];
bool check[1001];
int from[1001];
int inf = 987654321;

int main()
{
	int n,m;
	cin >> n>>m;
	for (int i = 0; i < m; i++)
	{
		int t1, t2, t3;
		cin >> t1 >> t2 >> t3;
		a[t1].push_back(Edge(t2, t3));
	}
	int start, end;
	cin >> start >> end;
	for (int i = 1; i <= n; i++)
	{
		dist[i] = inf;
	}
	dist[start] = 0;
	from[start] = -1;
	for (int k = 0; k < n-1; k++)
	{
		int m = inf + 1;
		int x = -1;
		for (int i = 1; i <= n; i++)
		{
			if (check[i] == false && m > dist[i])
			{
				m = dist[i];
				x = i;
			}
		}
		check[x] = true;
		for (int i = 0; i < a[x].size(); i++)
		{
			int y = a[x][i].to;
			if (dist[y] > dist[x] + a[x][i].cost)
			{
				dist[y] = dist[x] + a[x][i].cost;
				from[y] = x;
			}
		}
	}
	cout << dist[end] << '\n';
	stack<int> st;
	int x = end;
	while (x != -1)
	{
		st.push(x);
		x = from[x];
	}
	cout << st.size() << '\n';
	while (!st.empty())
	{
		cout << st.top() << ' ';
		st.pop();
	}
	cout << '\n';
}