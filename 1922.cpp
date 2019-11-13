#include <iostream>
#include <queue>
#include <functional>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> v[1001];
bool visit[1001];
long long ans;

int main()
{
	ios::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back(make_pair(b, c));
		v[b].push_back(make_pair(a, c));
	}
	visit[1] = true;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;
	for (auto p : v[1])
	{
		q.push(make_pair(p.second, p.first));
	}
	while (!q.empty())
	{
		auto p = q.top();
		q.pop();
		if (visit[p.second])
			continue;
		visit[p.second] = true;
		ans += p.first;
		for (auto s : v[p.second])
		{
			q.push(make_pair(s.second, s.first));
		}
	}
	cout << ans << '\n';
}