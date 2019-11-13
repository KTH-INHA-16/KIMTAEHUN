#include <iostream>
using namespace std;

int main(void)
{
	unsigned long long n, m;
	cin >> n >> m;
	unsigned long long num2=0;
	unsigned long long num5=0;
	for (unsigned long long i = 5; i <= n; i *= 5) {
		num5 += n / i;
	}
	for (unsigned long long i = 2; i <= n; i *= 2)
	{
		num2 += n / i;
	}
	for (unsigned long long i = 5; i <= m; i *= 5) {
		num5 -= m / i;
	}
	for (unsigned long long i = 2; i <= m; i *= 2)
	{
		num2 -= m / i;
	}
	for (unsigned long long i = 5; i <= n-m; i *= 5) {
		num5 -= (n-m) / i;
	}
	for (unsigned long long i = 2; i <= n-m; i *= 2)
	{
		num2 -= (n-m) / i;
	}
	if (num2 >= num5)
	{
		cout << num5 << endl;
	}
	else
	{
		cout << num2 << endl;
	}
}