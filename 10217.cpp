#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;

const int inf = 987654321;
typedef pair<int, pair<int,int>> p ;

int t;
int dist[101][10003];
vector<p> v[101];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while (t--)
	{
		for (int i = 0; i < 101; i++)
		{
			v[i].clear();
		}
		int n, m, k;
		cin >> n >> m >> k;
		for (int i = 0; i < 101; i++)
			for (int j = 0; j < 10003; j++)
				dist[i][j] = inf;
		for (int i = 0; i < k; i++)
		{
			int from, to, cost,time;
			cin >> from >> to >> cost >> time;
			v[from].push_back(make_pair(to,make_pair(cost,time)));
		}
		priority_queue<p, vector<p>, greater<p>> pq;
		pq.push(make_pair(0, make_pair(0,1)));
		dist[1][0] = 0;
		while (!pq.empty())
		{
			int cnt = pq.top().second.second;
			int cnt_money = pq.top().second.first;
			int cnt_time = pq.top().first;
			pq.pop();
			if (dist[cnt][cnt_money] < cnt_time)
				continue;
			for (int i = 0; i < v[cnt].size(); i++)
			{
				int next = v[cnt][i].first;
				int next_time = dist[cnt][cnt_money] + v[cnt][i].second.second;
				int next_money = cnt_money + v[cnt][i].second.first;
				if (next_money>m)
					continue;
				if (dist[next][next_money]>next_time)
				{
					dist[next][next_money] = next_time;
					pq.push(make_pair(next_time, make_pair(next_money, next)));
				}
			}
		}
		int ans = inf;
		for (int i = 0; i < 10003; i++)
		{
			if (dist[n][i] != inf)
				ans = min(ans, dist[n][i]);
		}
		if (ans == inf)
			cout << "Poor KCM\n";
		else
			cout << ans << '\n';
	}
}
