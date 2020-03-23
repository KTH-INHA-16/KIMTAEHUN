#include <vector>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int MAX = 500;
const int INF = 987654321;

int n, m;
vector<pair<int, int>> graph[MAX];
//�ִܰŸ� �������� trace�� ����
vector<pair<int, int>> trace[MAX];
bool visited[MAX][MAX];
//�湮 ������ a -> b�� �������� ����
//a ->b b->a�� �ٸ� �����̱� ����

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
		//�ּҰŸ��� ������ �ϱ� ���� ���ʿ��� ���� ����
		if (distance[curVertex] < cost)
			continue;
		for (int i = 0; i < graph[curVertex].size(); i++)
		{
			int neighbor = graph[curVertex][i].first;
			int neighborDistance = cost + graph[curVertex][i].second;

			//������ ���� ����
			if (graph[curVertex][i].second == -1)
				continue;

			if (distance[neighbor] > neighborDistance)
			{
				distance[neighbor] = neighborDistance;
				//�Ÿ��� ��ȣ�� �ٲپ� �Ÿ��� ���� �������� ����������
				pq.push(make_pair(-neighborDistance, neighbor));

				//trace�� ����(�ִ� �Ÿ��� ��� ã������)
				trace[neighbor].clear();
				trace[neighbor].push_back(make_pair(curVertex, neighborDistance));
			}
			else if (distance[neighbor] == neighborDistance)
			{
				//���� �ִܰŸ� �϶� �߰�
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
			//���� ������ ������ 1->2��� trace���� 2->1�� ���� ����Ǿ� �ֱ⿡
			//graph[curVertex][]�� �ƴ� graph[neighbor][]�� �����Ѵ�
			//ó�� ������ curVertex�� ���������� �����ϸ� ����
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