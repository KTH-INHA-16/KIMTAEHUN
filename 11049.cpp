#include <iostream>
#include <cstring>
using namespace std;

int a[501][2];
int d[501][501];

int go(int x, int y)
{
	if (d[x][y])
		return d[x][y];
	if (x == y)
		return 0;
	if (x + 1 == y)
		return a[x][0] * a[x][1] * a[y][1];
	int &ans = d[x][y];
	ans = -1;
	for (int i = x; i <= y; i++)
	{
		int t1 = go(x, i);
		int t2 = go(i + 1, y);
		if (ans == -1 || ans > t1 + t2 + a[x][0] * a[i][1] * a[y][1])
			ans = t1 + t2 + a[x][0] * a[i][1] * a[y][1];
	}
	return ans;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 2; j++)
			cin >> a[i][j];
	cout << go(0, n-1) << '\n';
}