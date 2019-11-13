#include <iostream>
#include <cstdlib>
using namespace std;

int square(int x, int y)
{
	return (x / 3) * 3 + (y / 3);
}

int a[10][10];
int c[10][10];
int c2[10][10];
int c3[10][10];
int n = 9;

void go(int z)
{
	if (z == 81)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << a[i][j] << ' ';
			}
			cout << '\n';
		}
		exit(0);
	}
	int x = z / 9;
	int y = z % 9;
	if (a[x][y] != 0)
	{
		go(z + 1);
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			if (c[x][i] == 0 && c2[y][i] == 0 && c3[square(x, y)][i] == 0)
			{
				c[x][i] = true;
				c2[y][i] = true;
				c3[square(x, y)][i] = true;
				a[x][y] = i;
				go(z + 1);
				a[x][y] = 0;
				c[x][i] = false;
				c2[y][i] = false;
				c3[square(x, y)][i] = false;
			}
		}
	}
}

int main(void)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
			if (a[i][j] != 0)
			{
				c[i][a[i][j]] = true;
				c2[j][a[i][j]] = true;
				c3[square(i, j)][a[i][j]] = true;
			}
		}
	}
	go(0);
	return 0;
}