#include <iostream>
#include <cstring>
using namespace std;

int a[10001];

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int left = 0, right = 0, sum = a[0], ans = 0;
	while (left <= right && right < n)
	{
		if (sum < m)
		{
			right += 1;
			sum += a[right];
		}
		else if (sum == m)
		{
			ans += 1;
			right += 1;
			sum += a[right];
		}
		else if (sum > m)
		{
			sum -= a[left];
			left += 1;
			if (left > right&&left < n)
			{
				right = left;
				sum = a[left];
			}
		}
	}
	cout << ans << '\n';
}