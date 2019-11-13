#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int N;
	cin >> N;
	vector<int> v(N+1);
	for (int i = 1; i <= N; i++)
	{
		cin >> v[i];
	}
	vector<int> d(N + 1);
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			d[i] = max(d[i], (d[i - j] + v[j]));
		}
	}
	cout << d[N] << endl;
}