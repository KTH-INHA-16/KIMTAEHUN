#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	long long n, m;
	cin >> n >> m;
	vector <long long> v1(m);
	for (int i = 0; i < m; i++)
	{
		cin >> v1[i];
	}
	if (n <= m)
	{
		cout << n;
		return 0;
	}
	long long left = 1;
	long long right = 2000000000LL * 1000000LL;;
	long long ans = 0;
	long long time;
	unsigned long long ride = 0;
	while (left <= right)
	{
		long long mid = (left + right) / 2;
		long long save = 0;
		ride = m;
		for (int i = 0; i < m; i++)
		{
			ride += mid / v1[i];
		}
		if (ride >= n)
		{
			time = mid;
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
		
	}
	ride = m;
	for (int i = 0; i < m; i++)
	{
		ride += (time - 1) / v1[i];
	}
	for (int i = 0; i < m; i++)
	{
		if (time%v1[i] == 0)
			ride++;
		if (ride == n)
		{
			cout << i + 1 << endl;
			break;
		}
	}
}