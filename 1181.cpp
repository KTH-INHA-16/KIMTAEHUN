#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool cmp(pair<int, string> &a, pair<int, string> &b)
{
	if (a.first == b.first)
		return a.second < b.second;
	return a.first < b.first;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector <pair<int,string>>v;
	for (int i = 0; i < n; i++)
	{
		string a;
		cin >> a;
		bool flag = false;
		if (!v.empty())
		{
			for (int j = 0; j < v.size(); j++)
			{
				if (a == v[j].second)
					flag = true;
			}
		}
		if (!flag)
		{
			v.push_back(make_pair(a.size(), a));
		}
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i].second << '\n';
	}
	
}