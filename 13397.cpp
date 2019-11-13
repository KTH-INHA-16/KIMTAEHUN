#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int n, m;
	cin >> n >> m;
	vector <int> v(n);
	vector <int> v2(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		v2[i] = v[i];
	}
	sort(v2.begin(), v2.end());
	int left = 0;
	int right = v2.back();
	int ans = right;
	while (left <= right)
	{
		int mid = (left + right) / 2;

		int n = v.size();
		int t1 = v[0];
		int t2 = v[0];
		int ans = 1;
		for (int i = 1; i < n; i++)
		{
			if (t1 > v[i])
				t1 = v[i];
			if (t2 < v[i])
				t2 = v[i];
			if (t2 - t1 > mid)
			{
				ans += 1;
				t1 = v[i];
				t2 = v[i];
			}

		}
		if (ans <= m)
		{
			right = mid - 1;
			if (ans > mid)
			{
				ans = mid;
			}
		}
		else
		{
			left = mid + 1;
		}

	}
	cout << ans << endl;
}