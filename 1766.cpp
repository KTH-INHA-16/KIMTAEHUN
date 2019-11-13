#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <functional>
using namespace std;

int n, m,x,y;
vector<vector<int>> v;
int visit[32001];
priority_queue<int,vector<int>,less<int>> pq;

int main()
{
	cin >> n >> m;
	v.resize(n + 1);
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		v[x].push_back(y);
		visit[y] += 1;
		//�켱������ �ø���.(y�� �޼����� �з���)
	}
	for (int i = 1; i <= n; i++)
	{
		if (visit[i] == 0)
			pq.push(-i);
		//0�� ���� �ؾ��ϴ°͵� �켱���� ť�� ����
		//-���ִ� ������ �������� ���� ������ �ϱ�����
	}
	for (int k = 0; k < n; k++)
	{
		int x = -pq.top();
		pq.pop();
		cout << x << ' ';
		//���� Ǯ��� �ϴ� ���� ���
		for (int i = 0; i < v[x].size(); i++)
		{
			int y = v[x][i];
			//�޴ܰ� ������ ������
			visit[y] -= 1;
			//�ش� �ܰ��� ������ ����
			if (visit[y] == 0)
				pq.push(-y);
			//0�̸� �ش� ���� �켱���� ť�� ����
		}
	}
	cout << '\n';
}