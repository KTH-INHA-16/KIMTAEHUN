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
		for (int k = 1; k <= i * 2 + 1; k++)
		{
			if (k % 2 == 0)
				cout << " ";
			else
				cout << "*";
		}
		cout << endl;
	}
}