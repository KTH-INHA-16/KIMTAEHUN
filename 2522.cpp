#include <iostream>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <= n - 1 - i; j++)
			cout << " ";
		for (int k = 1; k <= i + 1; k++)
			cout << "*";
		cout << endl;
	}
	for (int i = 0; i < n - 1; i++)
	{
		for (int k = 1; k <= i + 1; k++)
			cout << " ";
		for (int j = 1; j <= n - 1 - i; j++)
			cout << "*";
		cout << endl;
	}
}