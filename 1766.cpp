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
		//우선순위를 늘린다.(y는 뒷순위로 밀려남)
	}
	for (int i = 1; i <= n; i++)
	{
		if (visit[i] == 0)
			pq.push(-i);
		//0인 먼저 해야하는것들 우선순위 큐에 삽입
		//-해주는 이유는 낮은값이 먼저 나오게 하기위해
	}
	for (int k = 0; k < n; k++)
	{
		int x = -pq.top();
		pq.pop();
		cout << x << ' ';
		//먼저 풀어야 하는 문제 출력
		for (int i = 0; i < v[x].size(); i++)
		{
			int y = v[x][i];
			//뒷단계 문제를 가져옴
			visit[y] -= 1;
			//해당 단계의 순위를 낮춤
			if (visit[y] == 0)
				pq.push(-y);
			//0이면 해당 문제 우선순위 큐에 삽입
		}
	}
	cout << '\n';
}