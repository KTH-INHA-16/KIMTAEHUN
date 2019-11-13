#include <iostream>
using namespace std;

int main(void)
{
	int a, b;
	do
	{
		cin >> a >> b;
		if (a == 0 && b == 0)
			break;
		cout << a + b << endl;
	} while (true);
}