#include <vector>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int MAX = 500;
const int INF = 987654321;

int n, m;
vector<pair<int, int>> graph[MAX];
//최단거리 정점들을 trace에 담음
vector<pair<int, int>> trace[MAX];
bool visited[MAX][MAX];
//방문 한점을 a -> b의 형식으로 저장
//a ->b b->a는 다른 간선이기 때문

vector<int> dijkstra(int start, int vertex)
{
	vector<int> distance(vertex, INF);
	distance[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, start));

	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int curVertex = pq.top().second;
		pq.pop();
		//최소거리를 가지게 하기 위해 불필요한 과정 없앰
		if (distance[curVertex] < cost)
			continue;
		for (int i = 0; i < graph[curVertex].size(); i++)
		{
			int neighbor = graph[curVertex][i].first;
			int neighborDistance = cost + graph[curVertex][i].second;

			//삭제된 간선 무시
			if (graph[curVertex][i].second == -1)
				continue;

			if (distance[neighbor] > neighborDistance)
			{
				distance[neighbor] = neighborDistance;
				//거리의 부호를 바꾸어 거리가 작은 정점부터 꺼내지도록
				pq.push(make_pair(-neighborDistance, neighbor));

				//trace를 갱신(최단 거리를 계속 찾기위함)
				trace[neighbor].clear();
				trace[neighbor].push_back(make_pair(curVertex, neighborDistance));
			}
			else if (distance[neighbor] == neighborDistance)
			{
				//같은 최단거리 일때 추가
				trace[neighbor].push_back(make_pair(curVertex, neighborDistance));
			}
		}
	}
	return distance;
}

void bfs(int destination)
{
	queue<int> q;
	q.push(destination);

	while (!q.empty())
	{
		int curVertex = q.front();
		q.pop();

		for (int i = 0; i < trace[curVertex].size(); i++)
		{
			int neighbor = trace[curVertex][i].first;
			if (visited[curVertex][neighbor])
				continue;
			//원래 정점간 연결이 1->2라면 trace에는 2->1로 현재 연결되어 있기에
			//graph[curVertex][]가 아닌 graph[neighbor][]로 봐야한다
			//처음 들어오는 curVertex이 도착점임을 생각하면 쉽다
			for (int i = 0; i < graph[neighbor].size(); i++)
				if (graph[neighbor][i].first == curVertex)
					graph[neighbor][i].second = -1;
			q.push(neighbor);
		}
	}
}

int main()
{
	while (1)
	{
		memset(visited, false, sizeof(visited));
		memset(trace, 0, sizeof(trace));
		for (int i = 0; i < MAX; i++)
			graph[i].clear();
		cin >> n >> m;
		if (n == 0 && m == 0)
			break;
		int s, d;
		cin >> s >> d;
		for (int i = 0; i < m; i++)
		{
			int x, y, z;
			cin >> x >> y >> z;
			graph[x].push_back(make_pair(y, z));
		}
		dijkstra(s, n);
		bfs(d);
		vector<int> result = dijkstra(s, n);
		if (result[d] == INF)
			cout << -1 << '\n';
		else
			cout << result[d] << '\n';
	}
}