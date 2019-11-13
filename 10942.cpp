#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <stdio.h>
#include <string.h>
using namespace std;

int d[2001][2001];
int a[2001];

int go(int i, int j)
{
	if (i == j)
		return 1;
	else if (i + 1 == j)
	{
		if (a[i] == a[j])
			return 1;
		else
			return 0;
	}
	if (d[i][j] >= 0)
		return d[i][j];
	if (a[i] != a[j])
		return d[i][j] = 0;
	else
		return d[i][j] = go(i + 1, j - 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	memset(d, -1,sizeof(d));
	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		cout << go(a, b) << '\n';
	}

}