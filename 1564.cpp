#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	long long k, n;
	cin >> k >> n;
	vector<long long> a(k);
	for (int i = 0; i < k; i++)
	{
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	long long  left = 1;
	long long right = a.back();
	long long ans = 0;

	while (left <= right)
	{
		
		long long mid = (left + right) / 2;
		//cout << left << " " << right << " " << mid <<endl;
		long long count = 0;
		for (int i = 0; i < k; i++)
		{
			count += a[i] / mid;
		}
		//cout << "count : " << count << endl;
		if (count >= n)
		{
			ans = mid;
			left = mid + 1;
		}
		else if(count<n)
		{
			
			right = mid - 1;
		}
		
	}
	cout << ans << endl;
}