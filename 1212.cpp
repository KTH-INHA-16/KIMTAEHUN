#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void)
{
	string a;
	cin >> a;
	long long s = 0;
	int count1 = 0;
	string b = "";

	while (s<a.size())
	{
		int n = a[s] - '0';
		if (n == 0 && s==0)
		{
			cout << "0";
			break;
		}
		else if (n > 3)
		{
			while (n > 0)
			{
				int r = n % 2;
				b += (char)(r + '0');
				n /= 2;
			}
			reverse(b.begin(), b.end());
			cout << b;
			b = "";
		}
		else
		{
			if (n == 3 && s != 0)
				cout << "011";
			else if (n == 3 && s == 0)
				cout << "11";
			if (n == 1 && s != 0)
				cout << "001";
			else if (n == 1 && s == 0)
				cout << "1";
			if (n == 2 && s != 0)
				cout << "010";
			else if (n == 2 && s == 0)
				cout << "10";
			if (n == 0 && s != 0)
				cout << "000";

		}
		s++;
	}
	cout << endl;
}