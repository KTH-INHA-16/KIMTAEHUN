#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

vector<int> a[10001];
int ind[10001];
int work[10001];
int d[10001];
int n;

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int t;
		cin >> t;
		work[i] = t;
		int p;
		cin >> p;
		for (int j = 0; j < p; j++)
		{
			int x;
			cin >> x;
			a[x].push_back(i);
			ind[i] += 1;
		}
	}
	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		if (ind[i] == 0)
		{
			q.push(i);
			d[i] = work[i];
		}
	}
	for (int k = 0; k < n; k++)
	{
		int x = q.front();
		q.pop();
		for (int i = 0; i < a[x].size(); i++)
		{
			int y = a[x][i];
			ind[y] -= 1;
			if (d[y] < work[y] + d[x])
			{
				d[y] = work[y] + d[x];
			}
			if (ind[y]==0)
			{
				q.push(y);
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (ans < d[i])
			ans = d[i];
	}
	cout << ans << '\n';
}