#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> a[501];
pair<bool,int> check[501];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m;
	cin >> n>>m;
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	check[1].first = true;
	queue<int> q;
	q.push(1);
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int i = 0; i < a[x].size(); i++)
		{
			int y = a[x][i];
			if (check[y].first != true)
			{
				if (check[y].second <= 2)
				{
					q.push(y);
					check[y].second = check[x].second + 1;
					check[y].first = true;
				}
			}
		}
	}
	int ans = 0;
	for (int i = 2; i <= n; i++)
	{
		if (check[i].second <= 2&&check[i].first==true)
			ans += 1;
	}
	cout << ans << '\n';
}