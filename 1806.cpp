#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int inf = 100001;
int main()
{
	ios::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> a(n+1);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int left = 0, right = 0;
	int sum = a[0];
	int ans = inf;
	while (left <= right && right < n)
	{
		if (sum < m)
		{
			right += 1;
			sum += a[right];
		}
		else if (sum == m)
		{
			if (ans > right - left + 1)
			{
				ans = right - left + 1;
			}
			right += 1;
			sum += a[right];
		}
		else if (sum > m)
		{
			if (ans > right - left + 1)
			{
				ans = right - left + 1;
			}
			sum -= a[left];
			left += 1;
		}

	}
	if (ans >= inf)
	{
		cout << 0 << '\n';
	}
	else
	cout << ans << '\n';
}