#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001][1001];
int d[1001][1001];
int n, m;

int max3(int a, int b, int c)
{
	int m1 = max(a, b);
	int m2 = max(b, c);
	return max(m1, m2);
}



int main(void)
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			d[i][j] = max3(d[i - 1][j], d[i][j - 1], d[i - 1][j - 1]) + arr[i][j];
		}
	}

	cout << d[n][m] << '\n';
}