#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool ans(int n)
{
	if (n < 2) {
		return false;
	}
	for (int i = 2; i*i <= n; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

int main(void)
{
	int n;
	cin >> n;

	vector<bool> v(1001);
	for (int i = 1; i <= 1000; i++)
	{
		v[i] = ans(i);
	}
	int count = 0;
	while (n--)
	{
		int k;
		cin >> k;
		if (v[k] == true)
		{
			count++;
		}
	}
	cout << count << endl;
}