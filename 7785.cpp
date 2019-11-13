#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <functional>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	set <string> s;
	for (int i = 0; i < n; i++)
	{
		string a,b;
		cin >> a>>b;
		if (b == "enter")
			s.insert(a);
		else
		{
			auto p = s.find(a);
			s.erase(p);
		}
	}
	vector<string> v;
	for (auto i = s.begin(); i != s.end(); i++)
	{
		v.push_back(*i);
	}
	sort(v.begin(), v.end(), greater<string>());
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << '\n';
	}
}