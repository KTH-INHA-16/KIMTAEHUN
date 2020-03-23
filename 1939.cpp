#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

class point
{
public:
	int x;long long y;
	point(int x, long long y) :x(x), y(y)
	{}
};

int n, m;
vector<point> a[100001];
bool check[100001];

bool bfs(int x, int y,long long mid)
{
	bool flag = false;
	check[x] = true;
	queue<point> q;
	q.push(point(x, mid));
	while (!q.empty())
	{
		auto p = q.front();
		q.pop();
		for (int i = 0; i < a[p.x].size(); i++)
		{
			int to = a[p.x][i].x;
			int heavy = a[p.x][i].y;
			if (check[to] == false)
			{
				if (mid <= heavy)
				{
					check[to] = true;
					q.push(point(to, mid));
					if (to == y)
					{
						flag = true;
					}
				}
			}
		}
	}
	return flag;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	long long right = 1000000001;
	long long left = 1;
	for (int i = 0; i < m; i++)
	{
		long long x, y, z;
		cin >> x >> y >> z;
		a[x].push_back(point(y, z));
		a[y].push_back(point(x, z));
	}
	int from, to;
	cin >> from >> to;
	while (left <= right)
	{
		memset(check, false, sizeof(check));
		long long mid = (left + right) / 2;
		bool flag = bfs(from, to, mid);
		if (flag == true)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	cout << right << '\n';
}