#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
using namespace std;

class Edge
{
public:
	int to, cost;
	Edge(int t1,int t2):to(t1),cost(t2)
	{}
};

int n, e;
vector<Edge> a[1001];
bool check[1001];
int dist[1001];
int inf = 100000000;

vector<int> dijkstra(int start) {
	for (int i = 1; i <= n; i++) {
		dist[i] = inf;
		check[i] = false;
	}
	dist[start] = 0;
	for (int k = 0; k < n - 1; k++) {
		int m = inf + 1;
		int x = -1;
		for (int i = 1; i <= n; i++) {
			if (check[i] == false && m > dist[i]) {
				m = dist[i];
				x = i;
			}
		}
		check[x] = true;
		for (int i = 0; i <a[x].size(); i++) {
			int y = a[x][i].to;
			if (dist[y] > dist[x] + a[x][i].cost) {
				dist[y] = dist[x] + a[x][i].cost;
			}
		}
	}
	return vector<int>(dist, dist + n +1);
}

int main()
{
	cin >> n >> e;
	for (int i = 0; i < e; i++)
	{
		int t1, t2, t3;
		cin >> t1 >> t2 >> t3;
		a[t1].push_back(Edge(t2, t3));
		a[t2].push_back(Edge(t1, t3));
		//양방향길이기 때문에 t1-t2 t2-t1의 길을 push해준다
	}
	int m1, m2;
	cin >> m1 >> m2;
	//중간에 거쳐야 할 점 m1-m2 m2-m1둘중 하나의 간선을 통과해야함
	vector<int> start = dijkstra(1);
	//1부터 n까지 최단거리
	vector<int> d1 = dijkstra(m1);
	//m1부터 n까지 최단거리
	vector<int> d2 = dijkstra(m2);
	//m2부터 n까지 최단거리
	int ans = start[m1] + d1[m2] + d2[n];
	//1->m1->m2->n거리
	int ans2 = start[m2] + d2[m1] + d1[n];
	//1->m2->m1->n거리
	if (ans > ans2)
		ans = ans2;
	if (ans >= inf)
		ans = -1;
	cout << ans << '\n';
}