#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int dist[101][101];
int via[101][101];
int inf = 100000000;

void go(int i, int j, vector<int>& path)
{
	if (via[i][j] == -1)
	{
		path.push_back(i);
		path.push_back(j);
		return;
		//���� ���� ���� ���� ��� �̸�?
	}
	int to = via[i][j];
	//���� �ϴ� ���� ������?
	go(i, to, path);
	//i->to
	path.pop_back();
	//�߰��� to�� ���� to�� �ߺ��Ǽ� ���ò��� ����
	go(to, j, path);
	//to->j
}

int main()
{
	fill(&via[0][0], &via[101][101], -1);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			dist[i][j] = i == j ? 0 : inf;
		}
	}
	for (int i = 0; i < m; i++)
	{
		int t1, t2, t3;
		cin >> t1 >> t2 >> t3;
		dist[t1][t2] = dist[t1][t2] > t3 ? t3 : dist[t1][t2];
	}
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (dist[i][j] > dist[i][k] + dist[k][j])
				{
					dist[i][j] = dist[i][k] + dist[k][j];
					via[i][j] = k;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (dist[i][j] >= inf)
				cout << 0 << ' ';
			else
				cout << dist[i][j] << ' ';
		}
		cout << '\n';
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (dist[i][j] >= inf || dist[i][j] == 0)
			{
				cout << "0"<<"\n";
				continue;
			}
			vector<int>path;
			go(i, j, path);
			cout << path.size() << ' ';
			for (int k = 0; k < path.size(); k++)
			{
				cout << path[k] << ' ';
			}
			cout << '\n';
			
		}
	}

}