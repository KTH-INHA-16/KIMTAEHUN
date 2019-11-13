#include <iostream>
#include <algorithm>
using namespace std;

long long a[100001];
long long d[100001];
int main(void)
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}

	for (int i = 1; i <= n; i++)
	{
		d[i] = a[i];
		if (i == 1)
			continue;
		if(a[i]<d[i-1]+a[i])
			d[i] =  d[i - 1] + a[i];
	}

	long long ans = d[1];
	for (int i = 2; i <= n; i++)
	{
		if (ans < d[i])
			ans = d[i];
	}

	cout << ans << endl;

}