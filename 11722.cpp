#include <iostream>
#include <algorithm>
using namespace std;

int a[1001];
int d[1001];
int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = n - 1; i >= 0; i--)
	{
		d[i] = 1;
		for (int j = n - 1; j >= i; j--)
		{
			if (a[i] > a[j] && d[i] < d[j] + 1)
				d[i] = d[j] + 1;
		}
	}

	int ans = d[0];
	for (int i = 1; i < n; i++)
	{
		if (ans < d[i])
			ans = d[i];
	}
	cout << ans << endl;
}