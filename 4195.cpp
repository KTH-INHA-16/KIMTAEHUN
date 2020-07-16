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
	//현재 노드가 집합의 루트라면
	//자신이 속한 집합을 찾았으므로 node 반환
	if (node == parent[node])
		return node;

	//현재 노드가 집합의 루트가 아니라면
	//노드의 루트에 대해 재귀 호출하면서 parent[node] 업데이트
	return parent[node] = find(parent[node]);
}

//집합을 합치는 함수
void merge(int node1, int node2)
{
	node1 = find(node1); //node1이 속한 집합을 찾음
	node2 = find(node2); //node2가 속한 집합을 찾음
							   //같은 집합이 아닐 경우에만 합친다
	if (node1 != node2)
	{
		//크기가 더 큰 집합으로 작은 집합이 들어감
		if (Size[node1] < Size[node2])
			swap(node1, node2);

		parent[node2] = node1; //node2 집합이 node1에 합쳐짐
		Size[node1] += Size[node2]; //node1의 집합 크기가 커짐
		Size[node2] = 0; //node2가 node1에 흡수되므로
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
			//union - find 의 핵심 -> 부모 묶기 
			if (p1 == p2)
				cout << max(Size[p1], Size[p2])<<'\n';
			else
			{
				merge(p1, p2);
				//하위 그룹과 상위 그룹을 합치는 과정
				cout << max(Size[p1], Size[p2]) << '\n';
			}
			
		}
	}
}