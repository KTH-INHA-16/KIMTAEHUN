#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

long long m[51] = { 1,1, };

int fibo(int x)
{
	if (x == 0)
	{
		return m[x];
	}
	if (x == 1)
	{
		return m[x];
	}
	if (m[x] > 0)
		return m[x];
	return m[x] = fibo(x - 1) + fibo(x - 2);
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		if (n == 0)
			printf("1 0\n");
		else if (n == 1)
			printf("0 1\n");
		else
		{
			fibo(n);
			printf("%lld %lld\n", m[n - 2], m[n - 1]);
		}
	}
}