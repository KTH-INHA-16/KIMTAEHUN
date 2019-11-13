#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void)
{
	int a;
	string b = "";
	cin >> a;

	if (a != 0)
	{
		while (a != 0)
		{
			if (a < 0)
			{
				int r = a % 2;
				if (r < 0)
					r *= -1;
				b += (char)(r + '0');
				if ((-a % 2) != 0)
				{
					a = (-a / 2) + 1;
				}
				else
					a = (-a / 2);
			}
			else
			{
				int r = a % 2;
				b += (char)(r + '0');
				a = -(a / 2);
			}
		}
		reverse(b.begin(), b.end());
		cout << b << endl;
	}
	else
		cout << "0" << endl;
	/*
	void go(int n)
	{
		if(n==0)
		{
			return;
			//반환 하면 안됨 쓸 데없는것 나와버림
		}

		if (n%2 == 0)
		{
			go(-(n/2));
			printf("0");
		}

		else
		{
			if (n > 0)
			{
				go(-(n/2));
			}

			else
			{
				go((-n+1)/2);
			}

			printf("1");
		}
	}*/
}