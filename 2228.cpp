#include <iostream>
#include <cstring>
using namespace std;

int a[200];
int d[200][200];
bool c[200][200];
int min_num = -32768 * 101;

int go(int n, int m)
{
	if (m == 0)
		return 0;
	if (n <= 0)
		return min_num;
	if (c[n][m])
		return d[n][m];
	c[n][m] = true;
	int &ans = d[n][m];
	ans = go(n - 1, m);
	int sum = 0;
	for (int i = n; i>=1; i--)
	{
		sum += a[i];
		int tmp = go(i - 2, m - 1) + sum;
		if (ans < tmp)
			ans = tmp;
	}
	return ans;
}


int main(void)
{
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	cout << go(n, m) << '\n';
}