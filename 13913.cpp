#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int dist[200001];
bool check[200001];
int from[200001];

int main(void)
{
	int n, m;
	cin >> n >> m;
	queue<int> q;
	dist[n] = 0;
	check[n] = true;
	from[n] = n;
	q.push(n);
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		if (now - 1 >= 0)
		{
			if (check[now-1] == false)
			{
				int next = now - 1;
				q.push(next);
				check[next] = true;
				from[next] = now;
				dist[next] = dist[now] + 1;
			}
		}
		if (now + 1 < 200001)
		{
			if (check[now+1] == false)
			{
				int next = now + 1;
				q.push(next);
				check[next] = true;
				from[next] = now;
				dist[next] = dist[now] + 1;
			}
		}
		if (now * 2 < 200001)
		{
			if (check[now*2] == false)
			{
				int next = now * 2;
				q.push(next);
				check[next] = true;
				from[next] = now;
				dist[next] = dist[now] + 1;
			}
		}
	}
	stack<int>ans;
	for (int i = m; i != n; i = from[i])
	{
		ans.push(i);
	}
	ans.push(n);
	cout << dist[m] << endl;
	while (!ans.empty())
	{
		cout << ans.top() << ' ';
		ans.pop();
	}
	cout << '\n';
}