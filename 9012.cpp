#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		string a;
		cin >> a;
		int asize = a.size()-1;
		int count = 0;
		int cn1 = 0;
		int cn2 = 0;
		while (true)
		{
			char check1 = '(';
			char check2 = ')';
			if (check1 == a[count])
				cn1++;
			else
			{
				cn2++;
				if (cn2 > cn1)
				{
					cout << "NO" << endl;
					break;
				}
			}
			if (asize == count)
			{
				if (cn1 == cn2)
				{
					cout << "YES" << endl;
					break;
				}
				else
				{
					cout << "NO" << endl;
					break;
				}
			}
			else
			count++;
		}
	}
}