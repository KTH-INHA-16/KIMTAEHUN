#include <iostream>
#include <algorithm>
using namespace std;

int a[1001];
int d1[1001];
int d2[1001];
int main(void)
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 0; i < n; i++)
	{
		d1[i] = 1;
		for (int j = 0; j <= i; j++)
		{
			if (a[j] < a[i] && d1[i] < d1[j] + 1)
				d1[i] = d1[j] + 1;
		}
	}

	for (int i = n - 1; i >= 0; i--)
	{
		d2[i] = 1;
		for (int j = n - 1; j >= i; j--)
		{
			if (a[i] > a[j] && d2[i] < d2[j] + 1)
				d2[i] = d2[j] + 1;
		}
	}

	int ans = d1[0] + d2[0] - 1;
	
	for (int i = 1; i < n; i++)
	{
		if (ans < d1[i] + d2[i] - 1)
			ans = d1[i] + d2[i] - 1;
	}

	cout << ans << endl;

}