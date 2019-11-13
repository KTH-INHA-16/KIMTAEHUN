#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Edge
{
public:
	int to, cost;
	Edge(int t, int c)
	{
		to = t;
		cost = c;
	}
};

const int inf = 100000000;
int d[501];
bool check[501];
vector<Edge> a[501];
int cnt[501];
//���� üũ

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int t1, t2, t3;
		cin >> t1 >> t2 >> t3;
		a[t1].push_back(Edge(t2, t3));
	}
	for (int i = 1; i <= n; i++)
	{
		d[i] = inf;
	}
	d[1] = 0;
	check[1] = true;
	queue<int> q;
	q.push(1);
	while (!q.empty())
	{
		int x = q.front();
		check[x] = false;
		//�ٽ� false �� ���ش�
		q.pop();
		for (Edge &e:a[x])
		{
			int to = e.to;
			int cost = e.cost;
			if (d[to] > d[x] + cost)
				//���� ���� �˰���
			{
				d[to] = d[x] + cost;
				if (check[to] == false)
				{
					q.push(to);
					cnt[to] += 1;
					check[to] = true;
					//�ٽ� true-> ����cycle���� ����
				}
				if (cnt[to] >= n)
					//n-1������ ����Ŭ ���� ����
					//�������� ���� ����Ŭ
				{
					cout << -1 << '\n';
					return 0;
				}
			}
		}
	}
	for (int i = 2; i <= n; i++)
	{
		if (d[i] >= inf)
			cout << "-1\n";
		else
			cout << d[i] << '\n';
	}

}