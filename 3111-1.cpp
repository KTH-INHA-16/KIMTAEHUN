#include <iostream>
#include <stack>
#include <algorithm>
#include <string>
using namespace std;

stack <char> l;
stack <char> r;
int side;
string a2;
string a, b;

bool check()
{
	if (side == 0)
	{
		if (l.size() < a.size())
		{
			return false;
		}
		else
		{
			string cnt = "";
			for (int i = 0; i < a2.size(); i++)
			{
				cnt += l.top();
				l.pop();
			}
			if (cnt != a2)
			{
				for (int i = cnt.size() - 1; i >= 0; i--)
				{
					l.push(cnt[i]);
				}
				return false;
			}
			else
			{
				return true;
			}
		}
	}
	else
	{
		if (r.size() < a2.size())
		{
			return false;
		}
		else
		{
			string cnt = "";
			for (int i = 0; i < a2.size(); i++)
			{
				cnt += r.top();
				r.pop();
			}
			if (cnt != a)
			{
				for (int i = cnt.size() - 1; i >= 0; i--)
				{
					r.push(cnt[i]);
				}
				return false;
			}
			else
			{
				return true;
			}
		}
	}
}



int main()
{
	cin >> a >> b;
	a2 = a;
	reverse(a2.begin(), a2.end());
	int left = 0;
	int right = b.size() - 1;
	while (left <= right)
	{
		if (side == 0)
		{
			l.push(b[left++]);
		}
		else
		{
			r.push(b[right--]);
		}
		if (check())
		{
			if (side == 0)
				side = 1;
			else
				side = 0;
		}
	}
	side = 1;
	while (!l.empty())
	{
		r.push(l.top());
		l.pop();
		check();
	}
	while (!r.empty())
	{
		cout << r.top();
		r.pop();
	}
	cout << '\n';
}