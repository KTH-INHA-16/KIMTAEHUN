#include <iostream>
#include <algorithm>
using namespace std;

int n;

int a[12];
int b[12];
int c[4];
int d[4];
long long min_val = 1000000000;
long long max_val = -1000000000;

void go(int cnt)
{
	if (cnt == n-1)
	{
		long long sum = a[0];
		for (int i = 1; i < n; i++)
		{
			if (b[i - 1] == 0)
				sum += a[i];
			else if (b[i - 1] == 1)
				sum -= a[i];
			else if (b[i - 1] == 2)
				sum *= a[i];
			else
				sum /= a[i];
		}
		max_val = max(sum, max_val);
		min_val = min(sum, min_val);
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		if (c[i] != 0)
		{
			c[i]--;
			b[cnt] = i;
			go(cnt + 1);
			c[i]++;
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < 4; i++)
	{
		cin >> c[i];
	}
	go(0);
	cout << max_val << '\n';
	cout << min_val << '\n';
}