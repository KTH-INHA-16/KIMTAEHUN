#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> a[50001];
bool check[50001];
int depth[50001];
int parent[50001];

int LCA(int a,int b)
{
	if (depth[a] > depth[b])
		//���̰� �������� b�̴�
		swap(a, b);
	while (depth[a] != depth[b])
		//���̰� ���� ������ �ø���
	{
		b = parent[b];
	}
	while (a != b)
		//a��b�� ������������ ��ȯ
	{
		a = parent[a];
		b = parent[b];
	}
	return b;
}

int main()
{
	ios::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int t1, t2;
		cin >> t1 >> t2;
		a[t1].push_back(t2);
		a[t2].push_back(t1);
	}
	depth[1] = 0;
	check[1] = true;
	parent[1] = 0;
	queue<int> q;
	q.push(1);
	while (!q.empty())
		//bfs�� ��� ����� �θ�� ���� ���ϱ�
	{
		int x = q.front();
		q.pop();
		for (int y : a[x])
		{
			if (check[y] == false)
			{
				depth[y] = depth[x] + 1;
				check[y] = true;
				parent[y] = x;
				q.push(y);
			}
		}
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int t1, t2;
		cin >> t1 >> t2;
		cout << LCA(t1, t2) << '\n';
	}
}