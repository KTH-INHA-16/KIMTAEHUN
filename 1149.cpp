#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a[3][1001];
int m[3][1001];

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[0][i]>>a[1][i]>>a[2][i];
	for (int i = 1; i <= n; i++)
	{
		m[0][i] = min(m[1][i - 1], m[2][i - 1]) + a[0][i];
		m[1][i] = min(m[0][i - 1], m[2][i - 1]) + a[1][i];
		m[2][i] = min(m[0][i - 1], m[1][i - 1]) + a[2][i];
	}
	cout << min(min(m[0][n], m[1][n]), m[2][n])<<'\n';
}