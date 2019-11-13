#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <string.h>
using namespace std;

bool check[20001];
int dist[20001];
int from[20001];
char how[20001];

int main(void)
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		memset(check, false, sizeof(check));
		memset(dist, 0, sizeof(dist));
		memset(from, 0, sizeof(from));
		int n, m;
		cin >> n >> m;
		check[n] = true;
		dist[n] = 0;
		how[n] = ' ';
		queue <int> q;
		q.push(n);
		while (!q.empty())
		{
			int now = q.front();
			q.pop();
			int next1 = (now*2)%10000;
			if (check[next1] == false)
			{
				q.push(next1);
				check[next1] = true;
				dist[next1] = dist[now] + 1;
				from[next1] = now;
				how[next1] = 'D';
			}
			int next2 = now-1;
			if (next2 == -1)
				next2 = 9999;
			if (check[next2] == false)
			{
				q.push(next2);
				check[next2] = true;
				dist[next2] = dist[now] + 1;
				from[next2] = now;
				how[next2] = 'S';
			}
			int next3 = (now % 1000) * 10 + now / 1000;
			if (check[next3] == false)
			{
				q.push(next3);
				check[next3] = true;
				dist[next3] = dist[now] + 1;
				from[next3] = now;
				how[next3] = 'L';
			}
			int next4 = (now / 10) + (now % 10) * 1000;
			if (check[next4] == false)
			{
				q.push(next4);
				check[next4] = true;
				dist[next4] = dist[now] + 1;
				from[next4] = now;
				how[next4] = 'R';
			}
		}
		string ans = "";
		while (n != m)
		{
			ans += how[m];
			m = from[m];
		}
		reverse(ans.begin(), ans.end());
		cout << ans << '\n';
	}
}