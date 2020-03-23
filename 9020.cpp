#include <iostream>
using namespace std;

int a[10001];

int main()
{
	for (int i = 2; i <= 10000; i++)
		a[i] = i;
	for (int i = 2; i <= 10000; i++)
	{
		for (int j = i; j <= 10000; j += i)
		{
			if (a[j] != i && a[j] % i == 0)
				a[j] = 0;
		}
	}
	int n;
	cin >> n;
	while (n--)
	{
		int k;
		cin >> k;
		if (a[k / 2] != 0)
		{
			cout << k / 2 << ' ' << k / 2<<'\n';
		}
		else
		{
			bool flag = false;
			for (int i = k / 2; i >= 0; i--)
			{
				for (int j = k / 2; j <= k; j++)
				{
					if (a[i] != 0 && a[j] != 0)
					{
						if (i + j == k)
						{
							cout << i << ' ' << j << '\n';
							flag = true;
							break;
						}
					}
				}
				if (flag)
					break;
			}
		}

	}
}