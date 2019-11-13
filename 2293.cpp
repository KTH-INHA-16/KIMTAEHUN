#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;

int d[10009];
int a[101];
int n, k;


int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	d[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= k; j++)
		{
			if (j - a[i] >= 0)
				d[j] += d[j - a[i]];
		}
	}
	cout << d[k] << '\n';
}