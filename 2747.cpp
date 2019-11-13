#include <iostream>
#include <cstring>
using namespace std;

long long m[100001];
int n;

long long fibo(int n)
{
	if (n == 1 || n == 0)
	{
		return m[n];
	}
	if (m[n] != -1)
	{
		return m[n];
	}
	return m[n] = fibo(n - 1) + fibo(n - 2);
}

int main()
{
	cin >> n;
	memset(m, -1, sizeof(m));
	m[0] = 0;
	m[1] = 1;
	cout << fibo(n) << '\n';

}