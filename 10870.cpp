#include <iostream>
using namespace std;

int m[21];

int fibo(int n)
{
	if (n <= 1)
		return m[n];
	if (m[n] > 0)
		return m[n];
	m[n] = fibo(n - 1) + fibo(n - 2);
	return m[n];
}

int main()
{
	m[1] = 1;
	int n;
	cin >> n;
	cout<<fibo(n)<<'\n';
}