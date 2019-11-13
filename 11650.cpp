#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int n;
	cin >> n;

	vector<pair<int, int>> a(n);
	while (n--)
	{
		cin >> a[n].first >> a[n].second;
	}

	sort(a.begin(), a.end());

	for (int i = 0; i < a.size(); i++)
	{
		printf("%d %d\n", a[i].first, a[i].second);
	}
}