#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a[51];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n);
	cout << a[0] * a[n - 1] << '\n';
}