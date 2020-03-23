#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include <queue>
using namespace std;

bool c[1000001];
//bfs하기 위한 해당 점 체크
int d[1000001];
//거리 저장 하기 위한 배열

int main(void)
{
	int n, k;
	cin >> n >> k;
	c[n] = true;
	d[n] = 0;
	queue<int> q;
	q.push(n);
	while (!q.empty())
	{
		int p = q.front();
		q.pop();
		if (p * 2 < 100001)
		{
			if (c[p * 2] == false)
			{
				q.push(p * 2);
				c[p * 2] = true;
				d[p * 2] = d[p];
			}
		}
		if (p - 1 >= 0)
		{
			if (c[p - 1] == false)
			{
				q.push(p - 1);
				c[p - 1] = true;
				d[p - 1] = d[p] + 1;
			}
		}
		if (p + 1 <= 100001)
		{
			if (c[p + 1] == false)
			{
				q.push(p + 1);
				c[p + 1] = true;
				d[p + 1] = d[p] + 1;
			}
		}
	}
	cout << d[k] << '\n';
}