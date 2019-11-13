#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void)
{
	string a;
	cin >> a;
	long long s = a.size();
	int count = 0;
	int b = 1;
	string a2 = "";
	int n2 = 0;
	while (s--)
	{
		if (count == 3)
		{
			a2 += (char)(n2 + '0');
			count = 0;
			b = 1;
			n2 = 0;
		}
		int n = a[s] - '0';
		n2 += n * b;
		b *= 2;
		count++;
		if (s == 0&&count!=3)
		{
			a2 += (char)(n2 + '0');
		}
		else if (s == 0 && count == 3)
		{
			a2 += (char)(n2 + '0');
		}
	}
	reverse(a2.begin(), a2.end());
	cout << a2 << endl;
}