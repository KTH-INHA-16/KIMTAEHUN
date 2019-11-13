#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <set>
using namespace std;

vector <int> a[100111];
int depth[100111];
bool check[100111];
int parent[100111];
int p[100111][18];

int lca(int u, int v)
{
	if (depth[u] < depth[v])
		swap(u, v);
	int log = 1;
	for (log = 1; (1 << log) <= depth[u]; log++);
	//u�� ���̺��� ���������� 2^n�� ���ش�
	log -= 1;
	//2^n-1�� ������ֱ� ����
	for (int i = log; i >= 0; i--)
	{
		if (depth[u] - (1 << i) >= depth[v])
		{
			//u�� ���̿��� 2^n�� ���� ���� v�� ���̺��� Ŭ�� 
			//u�� u�� 2^n��° �θ�� �̵���Ų��.
			u = p[u][i];
		}
	}
	if (u == v)
		return ;
	//���� ����Ʈ������ �����Ҷ�
	//���� ���̿� ���� ���� ���� ����Ʈ�� �ϼ� �ۿ� ����
	else
		//���� u!=v�� ���
	{
		for (int i = log; i >= 0; i--)
		{
			if (p[u][i] != 0 && p[u][i] != p[v][i])
				//u�� v�� 2^n�� �̵���ų�� ���� ������ ���� �̵��ϰ�
				//u�� 2^n�� �̵��������� 1�� �����ʵ��� �̵�
			{
				u = p[u][i];
				v = p[v][i];
			}
		}
		return parent[u];
		//���������� u�� �θ� ��ȯ = ���� ���� ��ȯ
		//���� ����Ʈ������ �ƴҶ�
	}
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
	check[1] = true;
	depth[1] = 0;
	parent[1] = 0;
	queue<int> q;
	q.push(1);
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int p : a[x])
		{
			int y = p;
			if (check[y] == false)
			{
				check[y] = true;
				depth[y] = depth[x] + 1;
				parent[y] = x;
				q.push(y);
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		p[i][0] = parent[i];
	}
	for (int j = 1; (1 << j) < n; j++)
	{
		for (int i = 1; i <= n; i++)
		{
			if (p[i][j - 1] != 0)
				p[i][j] = p[p[i][j - 1]][j - 1];
		}
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int t1, t2;
		cin >> t1 >> t2;
		cout << lca(t1, t2) << '\n';
	}
}