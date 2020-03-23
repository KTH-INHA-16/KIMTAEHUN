#include <iostream>
using namespace std;

int m[1001][1001];

int main()
{
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (i == j || j == 0)
			{
				m[i][j] = 1;
				continue;
			}
			m[i][j] = (m[i - 1][j] + m[i - 1][j-1])%10007;
		}
	}
	cout << m[n][k] << '\n';
}