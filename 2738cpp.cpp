#include <iostream>
using namespace std;

int a[101][101];
int b[101][101];
int c[101][101];

int main()
{
	int x, y;
	cin >> x >> y;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
			cin >> a[i][j];
	}
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			cin >> b[i][j];
			c[i][j] = a[i][j] + b[i][j];
		}
	}
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			cout << c[i][j] << ' ';
		}
		cout << '\n';
	}
}