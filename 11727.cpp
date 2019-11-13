#include <iostream>
using namespace std;

int d[1001];

int ans(int n)
{
	if (n == 1)
		return 1;
	if (n == 2)
		return 3;
	else
	{
		if (d[n] > 0)
			return d[n];
		else
			d[n] = (ans(n - 1)+2*ans(n-2)) % 10007;
		return d[n];
	}
}

int main(void)
{
	int n;
	cin >> n;

	cout << ans(n)  << endl;
}