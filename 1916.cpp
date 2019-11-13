#include <iostream>
#include <vector>
using namespace std;

int a[1001][1001];
int d[1001];
bool c[1001];
const int inf = 987654321;

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			a[i][j] = inf;
	for (int i = 0; i < m; i++)
	{
		int t1, t2, t3;
		cin >> t1 >> t2 >> t3;
		if (a[t1][t2] > t3)
			a[t1][t2] = t3;
	}
	int s, e;
	cin >> s >> e;
	for (int i = 1; i <= n; i++)
		d[i] = inf;
	d[s] = 0;
	for (int i = 0; i < n; i++)
	{
		int x = -1;
		int m = inf+1;
		for (int i = 1; i <= n; i++)
		{
			if (c[i] == false && m > d[i])
			{
				m = d[i];
				x = i;
			}
		}
		c[x] = true;
		for (int j = 1; j <= n; j++)
		{
			if (d[j] > d[x] + a[x][j])
				d[j] = d[x] + a[x][j];
		}
	}
	cout << d[e] << '\n';
}