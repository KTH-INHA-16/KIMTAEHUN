#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include <cstring>
#include <algorithm>
using namespace std;

const int inf = 987654321;
typedef pair<int, int> p;

int n, m, t, s, g, h,T;
vector<p> v[2001];
vector<int> e;
priority_queue<p, vector<p>, greater<p>> pq;
int dist [2001];

inline void make_clear()
{
	e.clear();
	for (int i = 0; i < 2001; i++)
		v[i].clear();
}

void go(int start)
{
	fill(dist, dist + 2001, inf);
	dist[start] = 0;
	pq.push(p(0, start));
	while (!pq.empty())
	{
		int cnt_dist = pq.top().first;
		int cnt = pq.top().second;
		pq.pop();
		for (int i = 0; i < v[cnt].size(); i++)
		{
			int next = v[cnt][i].first;
			int next_dist = v[cnt][i].second+dist[cnt];
			if (dist[next] > next_dist)
			{
				dist[next] = next_dist;
				pq.push(p(next_dist, next));
			}
		}
	}

}

int main()
{
	cin >> T;
	while (T--)
	{
		int ghdist;
		make_clear();
		cin >> n >> m >> t;
		cin >> s >> g >> h;
		for (int i = 0; i < m; i++)
		{
			int from, to, cost;
			cin >> from >> to >> cost;
			v[from].push_back(p(to, cost));
			v[to].push_back(p(from, cost));
			if (from == g && to == h)
			{
				ghdist = cost;
			}
			if (from == h && to == g)
			{
				ghdist = cost;
			}
		}
		for (int i = 0; i < t; i++)
		{
			int x;
			cin >> x;
			e.push_back(x);
		}

		//x - g - h - y -> a���
		//x - h - g - y -> b���
		//x - y -> c���
		//c ��δ� a��ο� b��� ��� ���� �Ÿ��� ������ �Ѵ�
		// �� ������ c��δ� ���̷�Ʈ ���� ���� �Ÿ��� ���ٸ�
		// �߰� ��θ� ���Ʊ� ����
		// �ٸ��� 2����δ� �߰� ��θ� �����ƴٴ� ���� �ƴ�
		go(s);
		int s_dist[2001];
		for (int i = 1; i <= n; i++)
			s_dist[i] = dist[i];
		int hdist = dist[h];
		int gdist = dist[g];

		go(g);
		int g_dist[2001];
		for (int i = 1; i <= n; i++)
			g_dist[i] = dist[i];

		go(h);
		int h_dist[2001];
		for (int i = 1; i <= n; i++)
			h_dist[i] = dist[i];

		sort(e.begin(), e.end());

		for (int i = 0; i < t; i++)
		{
			int end = e[i];
			int g = g_dist[end] + gdist + ghdist;
			int h = h_dist[end] + hdist + ghdist;
			int direct = s_dist[end] + ghdist;
			if (direct == g && direct == h)
				cout << end << ' ';
		}
		cout << '\n';
	}
}