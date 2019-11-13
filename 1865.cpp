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
			//도로는 양방향이기 때문에 양방향으로 해준다.
		}
		for (int i = 2*m; i < 2*m+w; i++) 
		{
			cin >> a[i].from >> a[i].to >> a[i].cost;
			a[i].cost *= -1;
			// 음수 경로 추가
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
					//밸만 포드 핵심!
					//출발할려는 점이 무한대가 아니고
					// 도착점 보다 출발점 + 소요시간
					//적으면 갱신
					// 이짓을 계속 한다.....(n까지)
				{
					dist[y] = dist[x] + z;
					if (i == n)
						negative = true;
					//간선 갯수를 n-1까지만 허용
					//n일때 갱신되면 무한대 사이클
				}
			}
		}
		if (negative==true)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}
}