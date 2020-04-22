#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;

int ans = 987654321;
int n, m;
int a[51][51];
bool check[51];
vector<pair<int, int>> house;
vector<pair<int, int>> chiken;

//모든 경우를 다하면 n!이 되기 때문에 시간초과
//다시 했던 경우는 세지 않는 것이 좋다.

void dfs(int cnt,int start)
{
	if (cnt == m)
	{
		int sum = 0;
		for (int i = 0; i < house.size(); i++)
		{
			int hy = house[i].first;
			int hx = house[i].second;
			int tmp = 987654321;
			for (int j = 0; j < chiken.size(); j++)
			{
				int cy = chiken[j].first;
				int cx = chiken[j].second;
				if (check[j])
				{
					tmp = min(((abs(cy - hy) + abs(cx - hx))), tmp);
				}
			}
			sum += tmp;
		}
		if (sum < ans)
			ans = sum;
		return;
	}
	else if (cnt > m)
		return;
	for (int i = start; i < chiken.size(); i++)
	{
		if (!check[i])
		{
			check[i] = true;
			dfs(cnt + 1,i+1);
			check[i] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == 1)
				house.push_back(make_pair(i, j));
			else if (a[i][j] == 2)
				chiken.push_back(make_pair(i, j));
		}
	}
	dfs(0,0);
	cout << ans << '\n';
}