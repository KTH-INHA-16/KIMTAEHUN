#include <iostream>
using namespace std;

int a[4000001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	for (int i = 2; i <= 4000000; i++)
		a[i] = i;
	for (int i = 2; i <= 4000000; i++)
	{
		for (int j = i; j <= 4000000; j+=i)
		{
			if (a[j] != i && a[j] % i == 0)
				a[j] = 0;
		}
	}
	while (1)
	{
		int n;
		cin >> n;
		if (n == 0)
			return 0;
		int ans = 0;
		for (int i = n+1; i <= n * 2; i++)
		{
			if (a[i] != 0)
				ans += 1;
		}
		cout << ans << '\n';
	}
}