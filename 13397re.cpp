#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int a[5001];

int main()
{
	cin >> n >> m;
	vector<int> b(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b.begin(), b.end());
	int left = 0;
	int right = 9999;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		int r1 = a[0], r2 = a[0];
		int s = 1;
		for (int i = 1; i < n; i++)
		{
			if (r1 < a[i])
				r1 = a[i];
			if (r2 > a[i])
				r2 = a[i];
			if (r1-r2 > mid)
			{
				r1 = a[i];
				r2 = a[i];
				s++;
			}
		}
		if (s > m)
		{
			left = mid + 1;
		}
		else
		{
			right = mid -1;
		}
	}
	cout << left << "\n";
}