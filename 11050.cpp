#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	int a=1, b=1, c=1;
	for (int i = 1; i <= n; i++)
		a *= i;
	for (int i = 1; i <= k; i++)
		b *= i;
	for (int i = 1; i <= n - k; i++)
		c *= i;
	long long ans = a / (b*c);
	cout << ans<<'\n';
}