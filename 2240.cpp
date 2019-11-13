#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m;
int a[10001];
int d[10001][31];

int go(int p, int t)
{
	if (p == n + 1 && t <= m)
		return 0;
	if (t > m)
		return 0;
	if (d[p][t] != -1)
		return d[p][t];
	int where = t % 2+1;
	d[p][t] = max(go(p + 1, t), go(p + 1, t + 1)) + (where == a[p] ? 1 : 0);
	return d[p][t];
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	memset(d, -1, sizeof(d));
	cout << max(go(1, 0), go(1, 1)) << '\n';
}