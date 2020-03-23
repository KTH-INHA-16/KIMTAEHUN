#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int gcd(int a, int b)
{
	if (a%b == 0)
	{
		return b;
	}
	return gcd(b, a%b);
}

int main()
{
	int n;
	cin >> n;
	vector <long long > a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	int g = a[1] - a[0];
	for (int i = 2; i < n; i++)
	{
		g = gcd(g, a[i] - a[i - 1]);
	}
	vector<int>result;
	for (int i = 2; i*i <= g; i++)
	{
		if (g%i == 0)
		{
			result.push_back(i);
			result.push_back(g / i);
		}
	}
	result.push_back(g);
	sort(result.begin(), result.end());
	result.erase(unique(result.begin(), result.end()), result.end());
	for (int i : result)
	{
		cout << i << ' ';
	}
	cout << '\n';
}