#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

string a;
int d[2599];
int c[2599][2599];

int main()
{
	cin >> a;
	int n = a.size();
	a = " " + a;
	for (int i = 1; i <= n; i++)
	{
		c[i][i] = 1;
	}
	for (int i = 1; i <= n - 1; i++)
	{
		if (a[i] == a[i + 1])
			c[i][i + 1] = 1;
	}

	for (int k = 2; k <= n; k++)
	{
		for (int i = 1; i <= n - k ; i++)
		{
			int j = i + k;
			if (a[i] == a[j] && c[i + 1][j - 1])
				c[i][j] = 1;
		}
	}
	d[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		d[i] = -1;
		for (int j = 1; j <= i; j++)
		{
			if (c[j][i])
			{
				if (d[i] == -1 || d[i] > d[j - 1] + 1)
					d[i] = d[j - 1] + 1;
			}
		}
	}
	cout << d[n] << '\n';
}