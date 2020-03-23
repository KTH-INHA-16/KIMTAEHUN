#include <iostream>
using namespace std;

int a[10001];

int main()
{
	int m, n;
	cin >> m >> n;
	for (int i = 2; i <= n; i++)
		a[i] = i;
	for (int i = 2; i <= n; i++)
	{
		for (int j = 2; j <= n; j++)
		{
			if (a[j] != i && a[j] % i == 0)
				a[j] = 0;
		}
	}
	int ans = -1;
	int sum = 0;
	for (int i = m; i <= n; i++)
	{
		if (a[i] != 0)
		{
			if (ans == -1)
				ans = a[i];
			sum += a[i];
		}
	}
	if (ans == -1)
		cout << ans << '\n';
	else
		cout << sum << '\n' << ans << '\n';
}