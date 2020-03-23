#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

int n,k;
string a[20];
int mo[20];
int len[20];
long long m[1 << 15][120];

long long gcd(long long t1, long long t2)
{
	if (t2 == 0)
		return t1;
	return gcd(t2, t1%t2);
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		len[i] = a[i].size();
	}
	cin >> k;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < len[i]; j++)
		{
			mo[i] = mo[i] * 10 + (a[i][j] - '0');
			mo[i] %= k;
		}
	}
	int ten[51];
	ten[0] = 1;
	for (int i = 1; i <= 50; i++)
	{
		ten[i] = ten[i - 1] * 10;
		ten[i] %= k;
	}
	m[0][0] = 1;
	for (int i = 0; i < (1 << n); i++)
	{
		for (int j = 0; j < k; j++)
		{
			for (int l = 0; l < n; l++)
			{
				if ((i&(1 << l)) == 0)
				{
					int next = j * ten[len[i]];
					next %= k;
					next += mo[i];
					next %= k;
					m[i | (1 << l)][next] += m[i][j];
				}
			}
		}
	}
	long long t1 = m[(1 << n) - 1][0];
	long long t2 = 1;
	for (long long i = 2; i <= n; i++)
		t2 *= i;
	long long g = gcd(t1, t2);
	t1 /= g;
	t2 /= g;
	cout << t1 << "/" << t2 << '\n';
}