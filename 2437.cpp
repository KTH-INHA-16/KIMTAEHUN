#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	if (a[0] != 1)
	{
		cout << 1 << '\n';
		return 0;
	}
	int sum = 1;
	for (int i = 1; i < n; i++)
	{
		if (a[i] > sum + 1)
			break;
		sum += a[i];
	}
	cout << sum + 1 << '\n';
}