#include <iostream>
using namespace std;

long long d[10000];

long long gcd(int a, int b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a%b);
}

int main(void)
{
	int n;
	cin >> n;
	
	while (n--)
	{
		int k;
		cin >> k;

		for (int i = 1; i <= k; i++)
			cin >> d[i];

		long long ans = 0;

		for (int i = 1; i < k; i++)
		{
			for (int j = i+1; j <= k; j++)
			{
				ans += gcd(d[i], d[j]);
			}
		}
		cout << ans << endl;
	}
}