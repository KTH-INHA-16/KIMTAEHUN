#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Edge
{
public:
	int x, y, d;
	bool operator <(const Edge& other)const {
		return d < other.d;
	}
};

int parent[10001];
int v, e;

int find(int x)
{
	if (x == parent[x])
		return x;
	else
	{
		return parent[x] = find(parent[x]);
	}
}

void Union(int x, int y)
{
	x = find(x);
	y = find(y);

	parent[x] = y;
}


int main()
{
	cin >> v >> e;
	for (int i = 1; i <= v; i++)
		parent[i] = i;
	vector<Edge> a(e);
	for (int i = 0; i < e; i++)
	{
		cin >> a[i].x >> a[i].y >> a[i].d;
	}
	sort(a.begin(), a.end());
	long long ans = 0;
	for (int i = 0; i < e; i++)
	{
		Edge e = a[i];
		int x = find(e.x);
		int y = find(e.y);
		if (x != y)
		{
			Union(e.x, e.y);
			ans += e.d;
		}
	}
	cout << ans << '\n';
}