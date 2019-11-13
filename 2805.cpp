#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	long long input;
	vector <long long> v;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		v.push_back(input);
	}
	sort(v.begin(), v.end());
	long long left = 0;
	long long right = v[n - 1];
	long long ans = 0;

	while (left <= right)
	{
		long long mid = (left + right)/2;
		long long count = 0;
		//cout << left << " " << right << " " << mid << endl;
		for (int i = 0; i < n; i++)
		{
			if(v[i]-mid>0)
			count += (v[i] - mid);
		}
		//cout << "count : " << count << endl;
		if (count >= m)
		{
			ans = mid;
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	cout << ans << endl;
}