#include <iostream>
using namespace std;

int a[101];
int ans;

int find(int x)
{
	if (x == a[x])
		return x;
	else
		return a[x] = find(a[x]);
}

void Union(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x != y)
	{
		a[y] = x;
	}
}

int main(void)
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		a[i] = i;
	}
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		Union(x, y);
	}
	for (int i = 2; i <= n; i++)
	{
		if (find(1)== find(i))
			ans += 1;
	}
	cout << ans << '\n';
}