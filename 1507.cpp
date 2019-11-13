#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set>
using namespace std;

int dist[21][21];
int inf = 1000000000;
int check[21][21];

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> dist[i][j];
		}
	}
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			if (i == k)
				continue;
			for (int j = 1; j <= n; j++)
			{
				if (i == j)
					continue;
				if (k == j)
					continue;
				//i==k, i==j, k==j 3경우를 베재해야함
				if (dist[i][j] > dist[i][k] + dist[k][j])
					//최솟값이 갱신되는 경우?
				{
					cout << "-1\n";
					//틀린경우
					return 0;
				}
				if (dist[i][j] == dist[i][k] + dist[k][j])
					//최솟값이 같아지는경우
				{
					check[i][j] = true;
					//i->j는 안쓰는길
				}
			}
		}
	}
	//플로이드 와샬 알고리즘
	int ans = 0;

	for(int i=1;i<=n;i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (check[i][j] == false)
			{
				ans += dist[i][j];
			}
		}
	}
	cout << ans/2 << '\n';
}