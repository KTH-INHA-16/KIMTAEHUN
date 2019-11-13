#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

unsigned long long f[21] = { 1 };
bool b[21];

int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 1; i <= 20; i++)
	{
		f[i] = f[i-1]*i;
	}
	int n2;
	cin >> n2;
	if (n2 == 1)
	{
		unsigned long long k;
		int num = 0;
		cin >> k;
		vector<int> ans(n);
		for (int i = 0; i < n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (b[j] == true)
					continue;
				if (f[n - i-1] < k)
				{
					k -= f[n - i-1];
				}
				else
				{
					ans[i] = j;
					b[j] = true;
					break;
				}
			}
		}

		for (int i = 0; i < n; i ++)
		{
			printf("%d ", ans[i]);
		}
		printf("\n");
	}
	else if(n2==2)
	{
		vector<int> a(n);
		unsigned long long ans = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 1; j < a[i]; j++)
			{
				if (b[j] == false)
				{
					ans += f[n - i - 1];
				}
			}
			b[a[i]] = true;
		}
		cout << ans+1 << "\n";
	}
}