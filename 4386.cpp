#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>
using namespace std;

struct edge {
	int x, y; 
	double dist;
	edge(int x,int y, double dist):x(x),y(y),dist(dist)
	{}
};

int n;
pair<double, double> node[101];
vector<edge> e;
int parent[101];

int find(int x)
{
	if (parent[x] < 0)
		return x;
	else
		return find(parent[x]);
}

bool merge(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a == b)
		return false;
	parent[b] = a;
	return true;
}

inline double d(pair<double, double> a, pair<double, double> b)
{
	return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

bool cmp(edge& a, edge& b)
{
	if (a.dist != b.dist)
		return a.dist < b.dist;
	else
		if (a.y != b.y)
			return a.y < b.y;
		else
			return a.x < b.x;
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		double x, y;
		cin >> x >> y;
		node[i] = { x,y };
	}

	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			e.push_back({ i,j,d(node[i],node[j]) });
	sort(e.begin(), e.end(),cmp);
	memset(parent, -1, sizeof(parent));
	double ans = 0; int cnt = 0;
	for (int i = 0; i <= e.size(); i++)
	{
		if (merge(e[i].x, e[i].y))
		{
			ans += e[i].dist;
			if (++cnt == n - 1)
				break;
		}
	}
	printf("%.2f\n", ans);
}