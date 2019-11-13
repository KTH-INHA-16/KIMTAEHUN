#include <iostream>
using namespace std;

int main(void)
{
	int a, b, n;
	cin >> n;
	while (n >= 1)
	{
		cin >> a >> b;
		cout << a + b << endl;
		n--;
	}
}