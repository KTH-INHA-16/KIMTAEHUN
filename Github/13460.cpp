#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
using namespace std;

struct ba
{
	int dist, rx, ry, bx, by;
};
bool check[12][12][12][12];
int fx, fy;
queue<ba> q;
int n, m;
int map[11][11];
pair<int, int> d[] = { {1,0},{-1,0},{0,1},{0,-1} };

void move(int& x, int& y, int cnt)
{
	while (true)
	{
		x += d[cnt].first;
		y += d[cnt].second;
		if (map[x][y] == 1)
		{
			x -= d[cnt].first;
			y -= d[cnt].second;
			break;
		}
		else if (map[x][y] == 2)
			break;
	}
}

int main()
{
	cin >> n >> m;
	int a, b, c, d;
	for (int i = 0; i < n; i++)
	{
		string x;
		cin >> x;
		for (int j = 0; j < m; j++)
		{
			if (x[j] == '.')
				map[i][j] = 0;
			else if (x[j] == '#')
				map[i][j] = 1;
			else if (x[j] == 'O')
			{
				map[i][j] = 2;
				fx = i, fy = j;
			}
			else if (x[j] == 'R')
				a = i, b = j;
			else
				c = i, d = j;
		}
	}
	q.push({ 0, a, b, c, d });
	int ans = -1;
	check[a][b][c][d] = true;
	while (!q.empty())
	{
		auto p = q.front();
		q.pop();
		if (p.dist > 10)
			break;
		if (p.rx == fx && p.ry == fy)
		{
			ans = p.dist;
			break;
		}
		for (int i = 0; i < 4; i++)
		{
			int rx = p.rx, ry = p.ry;
			int bx = p.bx, by = p.by;
			move(rx, ry, i);
			move(bx, by, i);
			if (bx == fx && by == fy)
				continue;
			if (rx == bx && ry == by)
				//°ãÃÆÀ» °æ¿ì
			{
				if (i == 0)
					p.rx < p.bx ? rx-- : bx--;
				//->
				else if (i == 1)
					p.rx < p.bx ? bx++ : rx++;
				//<-
				else if (i == 2)
					p.ry < p.by ? ry-- : by--;
				//À§·Î
				else if(i==3)
					p.ry < p.by ? by++ : ry++;
				//¾Æ·¡·Î
			}
			if (!check[rx][ry][bx][by])
			{
				ba n = { p.dist + 1,rx,ry,bx,by };
				q.push(n);
				check[rx][ry][bx][by] = true;
			}
		}
	}
	cout << ans << '\n';
}