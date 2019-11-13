#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	string s;
	getline(cin, s);
	int i = 0;
	while (i<s.size())
	{
		if (s[i] >= 'a'&&s[i] <= 'z')
		{
			if (int(s[i]) + 13 > 122)
			{
				cout << char(s[i] + 13 - 26);
			}
			else
			{
				cout << char(s[i] + 13);
			}
		}
		else if (s[i] >= 'A'&&s[i] <= 'Z')
		{
			if (int(s[i]) + 13 > 90)
			{
				cout << char(s[i]+13-26);
			}
			else
			{
				cout << char(s[i] + 13);
			}
		}
		else
			cout << s[i];
		i++;
	}
	cout << endl;
}