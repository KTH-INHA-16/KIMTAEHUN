#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> a(m);
	vector<int> b(m);
	int ans = 0;
	for (int i = 0; i < m; i++)
	{
		cin >> a[i] >> b[i];
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	if (n <= 6)
	{
		if (a[0] > b[0] * n)
			cout << b[0] * n << '\n';
		else
			cout << a[0] << '\n';
	}
	else
	{
		int ans = 987654321;
		for (int i = 0; i <= (n / 6) + 1; i++)
		{
			ans = min(ans, a[0] * i + b[0] * max(n - 6 * i, 0));
		}
		cout << ans << '\n';
	}
}