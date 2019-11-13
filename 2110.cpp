#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int n, c;
	cin >> n >> c;
	vector <long long> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	long long left = 1;
	long long right = v[n-1]-v[0];
	long long cnt;
	long long ans = 1;
	while (left <= right)
	{
		long long mid = (left+right)/2;
		cnt = 1;
		int last = v[0];
		for (int i = 1; i < n; i++)
		{
			if (v[i] - last >= mid)
			{
				cnt += 1;
				last = v[i];
			}
		}
		if (cnt >= c)
		{
			if (ans < mid)
			{
				ans = mid;
			}
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
		
	}
	cout << ans << endl;
}