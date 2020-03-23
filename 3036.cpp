#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int gcd(int a, int b)
{
	return a % b ? gcd(b, a%b) : b;
}

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int tmp = 0;
	for (int i = 1; i < n; i++)
	{
		tmp = gcd(a[0], a[i]);
		cout << a[0] / tmp << '/' << a[i] / tmp << '\n';
	}
}