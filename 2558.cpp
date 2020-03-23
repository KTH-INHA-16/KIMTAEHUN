#include <iostream>
using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	int tmp = b;
	while (b > 0)
	{
		int c = b % 10;
		cout << a * c << '\n';
		b /= 10;
	}
	cout << tmp * a << '\n';
}