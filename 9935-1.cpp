#include <iostream>
#include <stack>
#include <string>
using namespace std;

string a;
string b;
bool erase[1000001];

int main(void)
{
	cin >> a >> b;
	if (b.size()==1)
	{
		for (int i = 0; i < a.size(); i++)
		{
			if (a[i] == b[0])
			{
				erase[i] = true;
			}
		}
	}
	else
	{
		stack<pair<int, int>> s;
		for (int i = 0; i < a.size(); i++)
		{
			if (a[i] == b[0])
			{
				s.push(make_pair(i, 0));
			}
			else
			{
				if (!s.empty())
				{
					auto p = s.top();
					if (a[i] == b[p.second + 1])
					{
						s.push(make_pair(i, p.second+1));
					
						if (p.second+1==b.size()-1)
						{
							for (int j = 0; j < b.size(); j++)
							{
								auto p = s.top();
								erase[p.first] = true;
								s.pop();
							}
						}
					}
					else
					{
						while (!s.empty())
						{
							s.pop();
						}
					}
				}
			}
		}
	}
	bool print = false;
	for (int i = 0; i < a.size(); i++)
	{
		if (erase[i])
		{
			continue;
		}
		printf("%c", a[i]);
		print = true;
	}
	if (!print)
	{
		cout << "FRULA";
	}
	cout << '\n';
}