#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			for (int k = 2; k < n; k++)
			{
				if (i == j || i == k || j == k)
					continue;
				int tmp = v[i] + v[j] + v[k];
				if (ans < tmp&&tmp <= m)
				{
					ans = tmp;
					if (ans == m)
					{
						cout << ans << '\n';
						return 0;
					}
				}
			}
		}
	}
	cout << ans << '\n';
}