#include <iostream>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int k = 1; k <= n - 1-i; k++)
		{
			cout << " ";
		}
		for (int j = 1; j <= 2 * i + 1; j++)
		{
			if (i == n - 1)
				cout << "*";
			else
			{
				if (j == 1)
					cout << "*";
				else if (j == 2 * i + 1)
					cout << "*";
				else
					cout << " ";
				
			}
		}
		cout << endl;
	}
}