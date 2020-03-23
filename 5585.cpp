#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a[] = { 500,100,50,10,5,1 };

int main()
{
	int n;
	cin >> n;
	int ans = 0;
	n = 1000 - n;
	for (int i = 0; i < 6; i++)
	{
		if (n == 0)
			break;
		if (n / a[i] > 0)
		{
			int m = n / a[i];
			n = n - a[i] * m;
			ans += m;
		}
	}
	cout << ans << '\n';
}