#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

typedef pair<int, int> p;

const int inf = 987654321;
int n, m;
vector<p> v[1001];
bool check[1001];
int dist[1001];
int parent[1001];

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		v[from].push_back(p(to, cost));
		v[to].push_back(p(from, cost));
	}
	fill(dist, dist + 1001, inf);
	priority_queue<p, vector<p>, greater<p>>pq;
	pq.push(p(0, 1));
	dist[1] = 0;
	check[1] = true;
	while (!pq.empty())
	{
		int cnt = pq.top().second;
		int cnt_cost = pq.top().first;
		pq.pop();
		if (cnt_cost > dist[cnt])
			continue;
		check[cnt] = true;
		//다익스트라에는 굳이 check를 해줄 필요가 없다
		//갱신이 여러번 가능 할수도 있기 때문에
		for (int i = 0; i < v[cnt].size(); i++)
		{
			int next = v[cnt][i].first;
			int next_cost = v[cnt][i].second + dist[cnt];
			if (dist[next] > next_cost&&!check[next])
			{
				dist[next] = next_cost;
				pq.push(p(next_cost, next));
				parent[next] = cnt;
				check[cnt] = true;
			}
		}
	}

	cout << n - 1 << '\n';
	for (int i = 2; i <= n; i++)
		cout << parent[i] << ' ' << i << '\n';

}