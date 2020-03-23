#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int n;
int a[26];
int main()
{
	cin >> n;
	vector<string> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	for (int i = 0; i < n; i++)
	{
		int cnt = 0;
		for (int j = v[i].size()-1; j >= 0; j--)
		{
			a[v[i][j] - 'A'] += pow(10, cnt++);
		}
	}
	vector<pair<int, int>> s;
	for (int i = 0; i < 26; i++)
	{
		if (a[i])
			s.push_back(make_pair(a[i], i));
	}
	sort(s.begin(), s.end());
	int ans = 0;
	int tmp = 9;
	for (int i = s.size()-1; i >= 0; i--)
	{
		ans += tmp * s[i].first;
		tmp--;
	}
	cout << ans << '\n';
}