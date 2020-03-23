#include <string>
#include <stack>
#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while (true)
	{
		bool flag = true;
		string s;
		stack<char> st;
		getline(cin, s);
		if (s.length() == 1 && s[0] == '.')
			break;

		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == '(')
				st.push('(');
			else if (s[i] == '[')
				st.push('[');
			else if (s[i] == ']')
			{
				if (!st.empty() && st.top() == '[')
					st.pop();
				else
				{
					flag = false;
					break;
				}
			}
			else if (s[i] == ')')
			{
				if (!st.empty() && st.top() == '(')
					st.pop();
				else
				{
					flag = false;
					break;
				}
			}
		}
		if (flag && st.empty())
			cout << "yse\n";
		else
			cout << "no\n";
	}
}