#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector <int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	int ans = 0;
	do {
		int check = 0;
		for (int i = 1; i < v.size(); i++)
		{
			check += abs(v[i] - v[i - 1]);
		}
		ans = max(ans, check);

	} while (next_permutation(v.begin(), v.end()));
	cout << ans << endl;
}