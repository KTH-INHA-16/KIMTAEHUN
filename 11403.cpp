#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
//Floyd-Warshall Algorithm
int d[101][101];
int inf = 100000000;

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			cin >> d[i][j];
			if (d[i][j] == 0)
				d[i][j] = inf;
		}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (d[i][j] > d[i][k] + d[k][j])
					d[i][j] = d[i][k] + d[k][j];
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (d[i][j] >= inf)
				cout << 0 << " ";
			else
				cout << 1 << ' ';
		}
		cout << '\n';
	}
}