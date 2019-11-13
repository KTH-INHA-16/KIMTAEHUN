#include <iostream>
#include <string>
using namespace std;

char a[37] = { "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ" };

int main(void)
{
	long long n;
	int b;
	cin >> n >> b;
	string a1 = "";
	long long count = 0;

	while (n >= b)
	{
		a1 = a1 + a[n%b];
		n = n / b;
	}
	if (n == b)
		a1 += a[n / b];
	else
		a1 += a[n%b];

	long long size = a1.size();

	for (int i = size-1; i >= 0; i--)
	{
		cout << a1[i];
	}
	cout << endl;

}