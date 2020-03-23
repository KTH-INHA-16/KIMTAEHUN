#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int a[51];
int n, m;
deque<int> d;
deque<int> l;
deque<int> r;

pair<int,int> check(int cnt)
{
	int cnt1 = 0, cnt2 = 0;
	while (true)
	{
		if (a[cnt] == l.front())
			break;
		int tmp = l.front();
		l.push_back(tmp);
		l.pop_front();
		cnt1 += 1;
	}
	while (true)
	{
		if (a[cnt] == r.front())
			break;
		int tmp = r.back();
		r.push_front(tmp);
		r.pop_back();
		cnt2 += 1;
	}
	if (cnt1 < cnt2)
	{
		l.pop_front();
		return	make_pair(2, cnt1);
	}
	else
	{
		r.pop_front();
		return make_pair(3, cnt2);
	}
}

void duplicate(int x)
{
	vector<int> v;
	if (x == 2)
	{
		while (!l.empty())
		{
			v.push_back(l.front());
			l.pop_front();
		}
		while (!d.empty())
		{
			d.pop_front();
		}
		while (!r.empty())
		{
			r.pop_back();
		}
		for (int i = 0; i < v.size(); i++)
		{
			d.push_back(v[i]);
			l.push_back(v[i]);
			r.push_back(v[i]);
		}
	}
	else
	{
		while (!r.empty())
		{
			v.push_back(r.front());
			r.pop_front();
		}
		while (!d.empty())
		{
			d.pop_front();
		}
		while (!l.empty())
		{
			l.pop_back();
		}
		for (int i = 0; i < v.size(); i++)
		{
			d.push_back(v[i]);
			l.push_back(v[i]);
			r.push_back(v[i]);
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		d.push_back(i);
		l.push_back(i);
		r.push_back(i);
	}

	for (int i = 0; i < m; i++)
		cin >> a[i];

	int ans = 0;
	for (int i = 0; i < m; i++)
	{
		if (a[i] == d.front())
		{
			d.pop_front();
			l.pop_front();
			r.pop_front();
		}
		else
		{
			auto p = check(i);
			ans += p.second;
			duplicate(p.first);
		}
	}
	cout << ans << '\n';
	
}