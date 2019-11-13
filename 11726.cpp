#include <iostream>
using namespace std;

long long d[1001];
long long ans(int n)
{
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;
	else
	{
		if (d[n] > 0)
			return d[n];
		d[n] = ans(n-2)+ans(n - 1);
		return d[n]%10007;
	}
}

int main(void)
{
	int n;
	cin >> n;
	cout << ans(n) << endl;
}