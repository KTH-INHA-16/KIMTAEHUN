#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
#include <cstring>
using namespace std;

const int inf = 987654321;

int mx[] = { 0,0,1,-1 };
int my[] = { 1,-1,0,0 };
int a[126][126];
bool check[126][126];
int dist[126][126];
int n,t;

typedef pair<pair<int, int>,int> p;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while (1)
	{
		memset(a, 0, sizeof(a));
		memset(check, false, sizeof(check));
		//memset은 inf에 대해 작동 x
		for (int i = 0; i < 126; i++)
			for (int j = 0; j < 126; j++)
				dist[i][j] = inf;
		cin >> n;
		if (n == 0)
			return 0;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> a[i][j];
		priority_queue<p, vector<p>, greater<p>> pq;
		pq.push(make_pair(make_pair(0,0),0));
		check[0][0] = true;
		//인접 행렬에 대한 다익스트라라고 쫄지마라
		//다음 정점으로 가야하는 비용이 더 적을 경우에만 갱신
		//초기 우선순위 값은 더하지 않았으므로 고려해야함
		while (!pq.empty())
		{
			int y = pq.top().first.second;
			int x = pq.top().second;
			int cost = pq.top().first.first;
			pq.pop();
			for (int i = 0; i < 4; i++)
			{
				int ny = y + my[i];
				int nx = x + mx[i];
				int ncost = cost + a[ny][nx];
				//ncost -> 누적합
				if (0 <= nx && nx < n && 0 <= ny && ny < n)
				{
					if (!check[ny][nx] && dist[ny][nx] > ncost)
						//방문하지 않았고 누적합이 더 적을때
					{
						check[ny][nx] = true;
						dist[ny][nx] = ncost;
						pq.push(make_pair(make_pair(ncost, ny), nx));
					}
				}
			}
		}
		cout << "Problem " << ++t <<": " <<a[0][0] + dist[n - 1][n - 1] << '\n';
	}
}