#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Edge
{
public:
	int start, to, cost;
};

const int inf = 100000000;
int d[501];

int main()
{
	int n, m;
	cin >> n >> m;
	vector<Edge> a(m);
	for (int i = 0; i < m; i++)
	{
		cin >> a[i].start >> a[i].to >> a[i].cost;
	}
	for (int i = 1; i <= n; i++)
	{
		d[i] = inf;
	}
	d[1] = 0;

	bool negative = false;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int x = a[j].start;
			int y = a[j].to;
			int w = a[j].cost;
			if (d[x]!=inf&&d[y] > d[x] + w)
			{
				d[y] = d[x] + w;
				if (i == n)
					negative = true;
			}
		}
	}
	if (negative)
	{
		cout << -1 << '\n';
	}
	else
	{
		for (int i = 2; i <= n; i++)
		{
			if (d[i] == inf)
				d[i] = -1;
			cout << d[i] << '\n';
		}
	}
}