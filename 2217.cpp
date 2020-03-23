#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const int &a, const int &b)
{
	return a > b;
}

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> cost(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end(),cmp);
	for (int i = 0; i < n; i++)
	{
		cost[i] = a[i] * (i + 1);
	}
	sort(cost.begin(), cost.end(), cmp);
	cout << cost[0] << '\n';
}