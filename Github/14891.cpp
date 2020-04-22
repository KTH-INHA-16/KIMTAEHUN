#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#include <deque>
using namespace std;

int k, num, t;
int a[5][9];

int main()
{
	for (int i = 1; i <= 4; i++)
		for (int j = 1; j <= 8; j++)
			scanf("%01d", &a[i][j]);
	deque<int> dq[5];
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 8; j++)
			dq[i].push_back(a[i][j]);
	}
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> num >> t;
		int idx = num;
		int tmpt = t;
		queue<pair<int, int>> q;
		q.push({ idx,tmpt });
		while (1)
		{
			if (idx == 4)
				break;
			idx++;
			tmpt *= -1;
			if (dq[idx - 1][2] != dq[idx][6])
				q.push({ idx,tmpt });
			else
				break;
		}
		idx = num;
		tmpt = t;
		while (1)
		{
			if (idx == 1)
				break;
			idx--;
			tmpt *= -1;
			if (dq[idx + 1][6] != dq[idx][2])
				q.push({ idx,tmpt });
			else
				break;
		}
		while (!q.empty())
		{
			int cur = q.front().first;
			int rotate = q.front().second;
			q.pop();
			if (rotate == 1)
			{
				int tmp = dq[cur].back();
				dq[cur].pop_back();
				dq[cur].push_front(tmp);
			}
			else
			{
				int tmp = dq[cur].front();
				dq[cur].pop_front();
				dq[cur].push_back(tmp);
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= 4; i++)
		if (dq[i].front())
			ans += pow(2, i - 1);
	cout << ans << '\n';
}