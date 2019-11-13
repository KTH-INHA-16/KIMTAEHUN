#include <iostream>
#include<cstring>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int a[50][50];
int d[50][50];
int dx[] = { 0,0,-1,1,-1,1,-1,1 };
int dy[] = { -1,1,0,0,1,1,-1,-1 };
int height;
int width;

void dfs(int x, int y, int cnt)
{
	d[x][y] = cnt;
	for (int k = 0; k < 8; k++)
	{
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (0 <= nx && nx < height &&
			0 <= ny && ny < width)
		{
			if (a[nx][ny] == 1
				&& d[nx][ny] == 0)
			{
				dfs(nx, ny, cnt);
			}
		}
	}
}

int main(void)
{
	while (true)
	{
		memset(a, 0, sizeof(a));
		memset(d, 0, sizeof(d));
		int w, h;
		cin >> w >> h;

		if (w == 0 && h == 0)
		{
			break;
		}
		height = h;
		width = w;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> a[i][j];
			}
		}

		int cnt = 0;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (a[i][j] == 1 && d[i][j] == 0)
				{
					dfs(i, j, ++cnt);
				}
			}
		}

		cout << cnt<<endl;
		
	}
}