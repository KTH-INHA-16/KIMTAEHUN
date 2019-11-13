#include <iostream>
#include <string>
using namespace std;

int a[51][51];
int b[51][51];

void flip(int x, int y)
{
	for (int i = x - 1; i <= x + 1; i++)
	{
		for (int j = y - 1; j <= y + 1; j++)
			a[i][j] = 1 - a[i][j];
	}
}

int main(void)
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			scanf_s("%1d", &a[i][j]);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			scanf_s("%1d", &b[i][j]);
	}
	int ans = 0;

	for (int i = 0; i < n - 2; i++)
	{
		for (int j = 0; j < m - 2; j++)
		{
			if (a[i][j] != b[i][j])
			{
				ans += 1;
				flip(i + 1, j + 1);
			}
		}
	}

	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < m; j++) 
		{
			if (a[i][j] != b[i][j]) 
			{
				cout << "-1\n";
				return 0;
			}
		}
	}
	cout << ans << '\n';
}