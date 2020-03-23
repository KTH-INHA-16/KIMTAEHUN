#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 987654321;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<pair<int, int>> a(n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i].first >> a[i].second;
		}
		sort(a.begin(), a.end());
		int cnt = INF;
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			if (a[i].second < cnt)
			{
				cnt = a[i].second;
				ans += 1;
			}
		}
		cout << ans << '\n';
	}
}