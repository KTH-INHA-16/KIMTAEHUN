#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
#include <stdio.h>
#include <cstring>
using namespace std;

map<string, int> m;
int parent[100000 + 1], Size[100000 + 1];
int t, n;

int find(int node)
{
	//���� ��尡 ������ ��Ʈ���
	//�ڽ��� ���� ������ ã�����Ƿ� node ��ȯ
	if (node == parent[node])
		return node;

	//���� ��尡 ������ ��Ʈ�� �ƴ϶��
	//����� ��Ʈ�� ���� ��� ȣ���ϸ鼭 parent[node] ������Ʈ
	return parent[node] = find(parent[node]);
}

//������ ��ġ�� �Լ�
void merge(int node1, int node2)
{
	node1 = find(node1); //node1�� ���� ������ ã��
	node2 = find(node2); //node2�� ���� ������ ã��
							   //���� ������ �ƴ� ��쿡�� ��ģ��
	if (node1 != node2)
	{
		//ũ�Ⱑ �� ū �������� ���� ������ ��
		if (Size[node1] < Size[node2])
			swap(node1, node2);

		parent[node2] = node1; //node2 ������ node1�� ������
		Size[node1] += Size[node2]; //node1�� ���� ũ�Ⱑ Ŀ��
		Size[node2] = 0; //node2�� node1�� ����ǹǷ�
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while (t--)
	{
		m.clear();
		int idx = 1;
		cin >> n;
		for (int i = 0; i < 100000 + 1; i++)
		{
			parent[i] = i;
			Size[i] = 1;
		}
		for (int i = 0; i < n; i++)
		{
			string a, b;
			cin >> a >> b;
			if (m.count(a) == 0)
				m[a] = idx++;
			if (m.count(b) == 0)
				m[b] = idx++;
			int p1 = find(m[a]);
			int p2 = find(m[b]);
			//union - find �� �ٽ� -> �θ� ���� 
			if (p1 == p2)
				cout << max(Size[p1], Size[p2])<<'\n';
			else
			{
				merge(p1, p2);
				//���� �׷�� ���� �׷��� ��ġ�� ����
				cout << max(Size[p1], Size[p2]) << '\n';
			}
			
		}
	}
}