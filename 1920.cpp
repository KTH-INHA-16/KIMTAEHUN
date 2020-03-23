#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n,m;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	cin >> m;
	vector<int> a(m);
	for (int i = 0; i < m; i++)
	{
		cin >> a[i];
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < m; i++)
	{
		bool b = false;
		int l = 0;
		int r = n - 1;
		while (l <= r)
		{
			int m = (l + r) / 2;
			if (v[m] == a[i])
			{
				b = true;
				break;
			}
			else if (v[m] > a[i])
			{
				r = m-1;
			}
			else if (v[m] < a[i])
			{
				l = m+1;
			}
		}
		if (b)
			cout << 1 << '\n';
		else
			cout << 0 << '\n';
	}
}