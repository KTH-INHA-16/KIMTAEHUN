#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(void)
{
	string a;
	cin >> a;
	stack<int> s;
	int ans = 0;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] == '(')
		{
			s.push(i);
		}
		else
		{
			if (s.top() + 1 == i)
			{
				s.pop();
				ans += s.size();
			}
			else
			{
				s.pop();
				ans += 1;
			}
		}
	}
	cout << ans << endl;
}