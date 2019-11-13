#include <iostream>
#include <algorithm>
using namespace std;

int a[10000];
int d[10000];

int main(void)
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 0; i < n; i++)
	{
		d[i] = a[i];
		for (int j = 0; j <= i; j++)
		{
			if (a[j] < a[i] && d[i] < d[j] + a[i])
				d[i] = d[j] + a[i];
		}
	}
	int ans = d[0];
	for (int i = 0; i < n; i++)
	{
		if (ans <= d[i])
			ans = d[i];
	}
	printf("%d\n", ans);
}