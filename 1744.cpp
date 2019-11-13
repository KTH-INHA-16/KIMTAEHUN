  #include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	vector <int>a;
	vector <int> b;
	vector <int> z;
	int one = 0;
	for (int i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		if (k < 0)
			b.push_back(k);
		if (k > 1)
			a.push_back(k);
		if (k == 0)
			z.push_back(0);
		if (k == 1)
			one++;
	}

	long long int undersum = 0;
	long long int sum = 0;

	sort(b.begin(), b.end());
	for (int i = 1; i < b.size(); i += 2)
	{
		undersum += b[i] * b[i - 1];
	}
	if (b.size() % 2 != 0)
	{
		if (z.size() == 0)
			undersum += b[b.size() - 1];
	}

	sort(a.begin(), a.end());

	for (int i = a.size() - 1; i >= 0; i -= 2)
	{
		sum += a[i] * a[i - 1];
	}
	if (a.size() % 2 != 0)
	{
		sum += a[0];
	}
	long long int ans = 0;
	ans = sum + undersum + one;
	cout << ans << endl;

}