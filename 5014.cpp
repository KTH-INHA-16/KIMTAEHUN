#include <iostream>
#include <queue>
using namespace std;

bool check[2000001];
int dist[2000001];

int main()
{
	int f,s,g;
	int up, down;
	cin >> f >> s >> g;
	cin >> up >> down;
	queue<int> q;
	check[s] = true;
	dist[s] = 0;
	q.push(s);
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		if (check[now + up] == false&&now+up<=f)
		{
			q.push(now + up);
			check[now + up] = true;
			dist[now + up] = dist[now] + 1;
		}
		if (check[now - down] == false && now - down >= 0)
		{
			q.push(now - down);
			check[now - down] = true;
			dist[now - down] = dist[now] + 1;
		}
	}
	if (check[g] == false)
	{
		cout << "use the stairs\n";
	}
	else
	{
		cout << dist[g] << '\n';
	}
}