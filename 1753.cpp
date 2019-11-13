#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cstring>
using namespace std;

class Edge
{
public:
	int to, cost;
	Edge(int t1, int t2) :to(t1), cost(t2)
	{}
};

vector<Edge> a[20001];
long long dist[20001];
bool check[20001];
long long inf = 1000000000000;
int v, e;
int start;

int main()
{
	cin >> v >> e >> start;
	for (int i = 0; i < e; i++)
	{
		int t1, t2, t3;
		cin >> t1 >> t2 >> t3;
		a[t1].push_back(Edge(t2, t3));
	}
	for (int i = 1; i <= v; i++)
	{
		dist[i] = inf;
	}
	dist[start] = 0;
	set<pair<int,int>> s;
	s.insert(make_pair(0,start));
	//�Ÿ����� �ް� �׵ڿ� ������ ����
	
	while (!s.empty())
	{
		auto p = *s.begin();
		s.erase(s.begin());
		int x = p.second;
		for (int i = 0; i < a[x].size(); i++)
		{
			int y = a[x][i].to;
			if (dist[y] > dist[x] + a[x][i].cost)
			{
				if (dist[y] != inf)
					//���� ó�� ���ŵȰ��� �ƴϸ�
					s.erase(s.find(make_pair(dist[y], y)));
				//y�� ������ ���� ���� �Ÿ� �� ���� y�� ����
				//���� �ϴ� ������ ����ؼ� �ִ� �Ÿ��� �����ϱ� ����
				dist[y] = dist[x] + a[x][i].cost;
				s.insert(make_pair(dist[y], y));
				//ª�� �Ÿ��� �����
			}
		}
	}
	for (int i = 1; i <= v; i++)
	{
		if (dist[i] >= inf)
		{
			cout << "INF\n";
		}
		else if(dist[i]<inf)
			cout << dist[i] << '\n';
	}

}