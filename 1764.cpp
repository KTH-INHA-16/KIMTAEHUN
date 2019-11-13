#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <functional>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m;
	cin >> n >> m;
	set<string> s;
	vector <string> v;
	for (int i = 0; i < n; i++)
	{
		string a;
		cin >> a;
		s.insert(a);
	}
	for (int i = 0; i < m; i++)
	{
		string b;
		cin >> b;
		auto p = s.find(b);
		if (p != s.end())
			v.push_back(*p);
	}
	sort(v.begin(), v.end(), less<string>());
	cout << v.size() << '\n';
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << '\n';
	}
}