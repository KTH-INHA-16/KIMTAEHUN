#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

long long a[31];
long long d[31];

int main(void)
{
	int n;
	cin >> n;
	a[1] = 1;
	a[2] = 3;
	for (int i = 3; i <= 30; i++)
	{
		a[i] = a[i - 1] + a[i - 2]*2LL;
	}
	d[1] = 1;
	d[2] = 3;
	for (int i = 3; i <= 30; i++)
	{
		long long b = 0;
		if (i % 2 == 1)
			b = a[(i - 1) / 2];
		else
			b = a[(i / 2)] + 2 * a[(i - 2) / 2];
		d[i] = (a[i] + b) / 2;
	}
	cout << d[n] << '\n';
}