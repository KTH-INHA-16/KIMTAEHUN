#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int dist[501];
const int inf = 987654321;

class Edge
{
public:
	int from, to, cost;
};

int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		memset(dist, 0, sizeof(dist));
		int n, m, w;
		cin >> n >> m >> w;
		vector<Edge> a(2*m+w);
		for (int i = 0; i < 2*m; i++)
		{
			cin >> a[i].from >> a[i].to >> a[i].cost;
			int t1, t2, t3;
			t1 = a[i].from;
			t2 = a[i].to;
			t3 = a[i].cost;
			i += 1;
			a[i].from = t2;
			a[i].to = t1;
			a[i].cost = t3;
			//���δ� ������̱� ������ ��������� ���ش�.
		}
		for (int i = 2*m; i < 2*m+w; i++) 
		{
			cin >> a[i].from >> a[i].to >> a[i].cost;
			a[i].cost *= -1;
			// ���� ��� �߰�
		}
		for (int i = 1; i <= n; i++)
			dist[i] = inf;
		dist[1] = 0;
		bool negative = false;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < 2*m+w; j++)
			{
				int x = a[j].from;
				int y = a[j].to;
				int z = a[j].cost;
				if (dist[x] != inf && dist[y] > dist[x] + z)
					//�븸 ���� �ٽ�!
					//����ҷ��� ���� ���Ѵ밡 �ƴϰ�
					// ������ ���� ����� + �ҿ�ð�
					//������ ����
					// ������ ��� �Ѵ�.....(n����)
				{
					dist[y] = dist[x] + z;
					if (i == n)
						negative = true;
					//���� ������ n-1������ ���
					//n�϶� ���ŵǸ� ���Ѵ� ����Ŭ
				}
			}
		}
		if (negative==true)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}
}