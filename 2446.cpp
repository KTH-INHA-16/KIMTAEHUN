#include <iostream>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j < i + 1; j++)
			cout << " ";
		for (int k = 1; k <= 2 * (n - i) - 1; k++)
			cout << "*";
		cout << endl;
	}
	for (int i = 1; i <= n-1; i++)
	{
		for (int j = 1; j <= n - i - 1; j++)
			cout << " ";
		for (int k = 1; k <= 2 * i + 1; k++)
			cout << "*";
		cout << endl;
	}
}