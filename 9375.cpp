#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		int flag = 0;
		cin >> n;
		string s;
		vector<pair<string, int>> v;
		for (int i = 0; i < n; i++)
		{
			cin >> s >> s;
			pair<string, int>p;
			for (int i = 0; i < v.size(); i++)
			{
				if (v[i].first == s)
				{
					++v[i].second;
					flag = 1;
					break;
				}
			}
			if (flag == 0)
			{
				p.first = s;
				p.second = 1;
				v.push_back(p);
			}
			flag = 0;
		}
		int ans = 1;
		for (int i = 0; i < v.size(); i++)
		{
			ans *= v[i].second + 1;
		}
		cout << ans - 1 << '\n';

	}
}