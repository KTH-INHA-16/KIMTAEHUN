#include <iostream>
#include <algorithm>
using namespace std;

long long a[100000];
long long d[100000];
int main(void)
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> a[i];

	d[1] = a[1];
	d[2] = d[1] + a[2];
	for (int i = 3; i <= n; i++)
	{
		d[i] = max(d[i - 1],max( (d[i - 2] + a[i]), (d[i - 3] + a[i - 1] + a[i])));
	}

	long long ans = 0;
	ans = d[n];
	printf("%lld\n", ans);
}