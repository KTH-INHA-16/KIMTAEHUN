#include <iostream>
#include <queue>
using namespace std;

bool check[201][201];
bool ans[201];

int main(void)
{
	int a, b, c;
	cin >> a >> b >> c;
	int sum = c;
	queue<pair<int, int>>q;
	q.push(make_pair(0, 0));
	check[0][0] = true;
	ans[c] = true;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		int z = sum-x-y;
		q.pop();
		int nx, ny, nz;
		// a - b
		nx = x;
		ny = y;
		nz = z;
		ny = nx + ny;
		nx = 0;
		if (ny >= b)
		{
			nx = ny - b;
			ny = b;
		}
		if (!check[nx][ny])
		{
			check[nx][ny] = true;
			q.push(make_pair(nx, ny));
			if (nx == 0)
			{
				ans[nz] = true;
			}
		}
		//a - c
		nx = x;
		ny = y;
		nz = z;
		nz = nx + nz;
		nx = 0;
		if (nz >= c)
		{
			nx = nz - c;
			nz = c;
		}
		if (!check[nx][ny])
		{
			check[nx][ny] = true;
			q.push(make_pair(nx, ny));
			if (nx == 0)
			{
				ans[nz] = true;
			}
		}
		// b - a
		nx = x;
		ny = y;
		nz = z;
		nx = nx + ny;
		ny = 0;
		if (nx >= a)
		{
			ny = nx - a;
			nx = a;
		}
		if (!check[nx][ny])
		{
			check[nx][ny] = true;
			q.push(make_pair(nx, ny));
			if (nx == 0)
			{
				ans[nz] = true;
			}
		}
		// b - c
		nx = x;
		ny = y;
		nz = z;
		nz = ny + nz;
		ny = 0;
		if (nz >= c)
		{
			ny = nz - c;
			nz = c;
		}
		if (!check[nx][ny])
		{
			check[nx][ny] = true;
			q.push(make_pair(nx, ny));
			if (nx == 0)
			{
				ans[nz] = true;
			}
		}

		// c - b
		nx = x;
		ny = y;
		nz = z;
		ny = nz + ny;
		nz = 0;
		if (ny >= b)
		{
			nz = ny - b;
			ny = b;
		}
		if (!check[nx][ny])
		{
			check[nx][ny] = true;
			q.push(make_pair(nx, ny));
			if (nx == 0)
			{
				ans[nz] = true;
			}
		}
		// c - a
		nx = x;
		ny = y;
		nz = z;
		nx = nx + nz;
		nz = 0;
		if (nx >= a)
		{
			nx = a;
			nz = nx - a;
		}
		if (!check[nx][ny])
		{
			check[nx][ny] = true;
			q.push(make_pair(nx, ny));
			if (nx == 0)
			{
				ans[nz] = true;
			}
		}
	}
	for (int i = 0; i <= c; i++)
	{
		if (ans[i] == true)
		{
			cout << i << ' ';
		}
	}
	cout << '\n';
}