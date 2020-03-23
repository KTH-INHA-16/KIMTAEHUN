#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	deque<int> d;
	while (t--)
	{
		string s;
		cin >> s;
		if (s == "push")
		{
			int x;
			cin >> x;
			d.push_back(x);
		}
		else if (s == "pop")
		{
			if (d.empty())
				cout << -1 << '\n';
			else
			{
				cout << d.front() << '\n';
				d.pop_front();
			}
		}
		else if (s == "size")
		{
			cout << d.size() << '\n';
		}
		else if (s == "empty")
		{
			if (d.empty())
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (s == "front")
		{
			if (d.empty())
				cout << -1 << '\n';
			else
				cout << d.front()<<'\n';
		}
		else if (s == "back")
		{
			if (d.empty())
				cout << -1 << '\n';
			else
				cout << d.back() << '\n';
		}
	}
}