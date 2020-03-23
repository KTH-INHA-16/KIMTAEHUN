#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <functional>
using namespace std;

const int inf = 987654321;

int n, m, x;
bool check[1001];
int go_dist[1001];
int back_dist[1001];
int dist[1001];
vector<pair<int,int>> v[1001];

void go(int start)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	//�켱���� ť ����
	pq.push(make_pair(0, start));
	//���� 0 ����� ����
	go_dist[start] = 0;
	//������ 0���� �ʱ�ȭ
	while (!pq.empty())
	{
		int cnt;
		do {
			cnt = pq.top().second;
			pq.pop();
		} while (!pq.empty() && check[cnt]);
		//�̹湮 ���� + ť�� �������� ������ ���� �˻�
		if (check[x])
			break;
		//�ش� ���� �湮�� ����
		check[cnt] = true;
		for (int i = 0; i < v[cnt].size(); i++)
		{
			int next = v[cnt][i].first;
			int cost = v[cnt][i].second;
			if (go_dist[next] > go_dist[cnt] + cost)
				//�Ÿ��� �� �ּҰ� �Ǹ� ���� > ���� + �״��� �̵����
			{
				go_dist[next] = go_dist[cnt] + cost;
				pq.push(make_pair(go_dist[cnt] + cost, next));
				//���� �� �켱���� ť�� �߰�
			}
		}
	}
}

void back(int end)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, x));
	back_dist[x] = 0;
	while (!pq.empty())
	{
		int cnt;
		do {
			cnt = pq.top().second;
			pq.pop();
		} while (!pq.empty() && check[cnt]);
		if (check[end])
			break;
		check[cnt] = true;
		for (int i = 0; i < v[cnt].size(); i++)
		{
			int next = v[cnt][i].first;
			int cost = v[cnt][i].second;
			if (back_dist[next] > back_dist[cnt] + cost)
			{
				back_dist[next] = back_dist[cnt] + cost;
				pq.push(make_pair(back_dist[cnt] + cost, next));
			}
		}
	}
}

void initialize()
{
	for (int i = 1; i <= n; i++)
		go_dist[i] = back_dist[i] = inf;
	memset(check, false, sizeof(check));
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> x;
	for (int i = 0; i < m; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		v[from].push_back(make_pair(to, cost));
		//�ܹ��� �׷���
	}

	for (int i = 1; i <= n; i++)
	{
		initialize();
		//�ʱ�ȭ �۾� inf�� memset �Ұ�
		go(i);
		int g = go_dist[x];
		initialize();
		back(i);
		int b = back_dist[i];
		dist[i] = g + b;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		ans = max(ans, dist[i]);
		//���� �����ɸ��� �ð�
	}
	cout << ans << '\n';
}