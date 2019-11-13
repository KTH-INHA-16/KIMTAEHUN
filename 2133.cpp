#include <iostream>
using namespace std;

long long d[31];

long long ans(int n)
{
	if (n == 0)
		return 1;
	else
	{
		if (d[n] > 0)
			return d[n];
		for (int i = 2; i <= n; i += 2) {
			d[i] = ans(i - 2) * 3;
			for (int j = i - 4; j >= 0; j -= 2) {
				d[i] += ans(j) * 2;
			}
		}
			return d[n];
	}
}

int main(void)
{
	int n;
	cin >> n;

	cout << ans(n) << endl;
}