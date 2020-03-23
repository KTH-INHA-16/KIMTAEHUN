#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int num = 666;
	int t = 1;
	while (1)
	{
		if (t == n)
		{
			break;
		}
		num += 1;
		int copy = num;
		string s;
		while (copy)
		{
			s += (copy % 10 + '0');
			copy /= 10;
		}
		copy = stoi(s);
		int six = 0;
		while (copy)
		{
			int tmp = copy % 10;
			if (tmp == 6)
				six += 1;
			else if (six < 3)
				six = 0;
			copy /= 10;
		}
		if (six >= 3)
			t += 1;
	}
	cout << num << '\n';
}