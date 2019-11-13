#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(void)
{
	long long  n;
	long long k;
	cin >> n >> k;
	long long left = 1;
	long long right = n * n;
	long long ans = 0;

	while (left <= right)
	{
		long long mid = (left + right) / 2;
		long long cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			cnt += min(n, mid / i);
		}
		if (k > cnt)
		{
			left = mid + 1;
		}
		else
		{
			ans = mid;
			right = mid - 1;
		}
	}
	cout << ans << endl;
}