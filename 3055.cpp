#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m;

pair<int,int> d;
int wcheck[51][51];
int scheck[51][51];
int s[51][51];
int w[51][51];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,-1,1 };

int main()
{
	cin >> n >> m;
	string a;
	vector<string> map(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		map[i] = a;
	}
	queue<pair<int, int>> water;
	queue<pair<int, int>> go;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 'X')
			{
				s[i][j] = -1;
				w[i][j] = -1;
			}
			else if (map[i][j] == '*')
			{
				water.push(make_pair(i, j));
				wcheck[i][j] = true;
			}
			else if (map[i][j] == 'D')
			{
				d.first = i;
				d.second = j;
				w[i][j] = -1;
			}
			else if (map[i][j] == 'S')
			{
				go.push(make_pair(i, j));
				scheck[i][j] = true;
			}
		}
	}
	while (!water.empty())
	{
		int x = water.front().first;
		int y = water.front().second;
		water.pop();
		for (int k = 0; k < 4; k++)
		{
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			if (wcheck[nx][ny] == false && w[nx][ny] != -1)
			{
				wcheck[nx][ny] = true;
				w[nx][ny] = w[x][y] + 1;
				water.push(make_pair(nx, ny));
			}
		}
	}
	while (!go.empty())
	{
		int x = go.front().first;
		int y = go.front().second;
		go.pop();
		for (int k = 0; k < 4; k++)
		{
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			if(scheck[nx][ny] == false && s[nx][ny] != -1)
			{
				if ((w[nx][ny] > s[x][y] + 1 || w[nx][ny] == 0)|| nx == d.first&&ny == d.second)
					//물의 닿지 않는 0인 경우도 생각해 주어야함
				{
					scheck[nx][ny] = true;
					s[nx][ny] = s[x][y] + 1;
					go.push(make_pair(nx, ny));
				}
			}
		}
	}
	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j < m; j++)
	//	{
	//		cout << w[i][j] << ' ';
	//	}
	//	cout << '\n';
	//}
	//cout << '\n';
	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j < m; j++)
	//	{
	//		cout << s[i][j] << ' ';
	//	}
	//	cout << '\n';
	//}
	if (s[d.first][d.second] == 0)
	{
		cout << "KAKTUS\n";
	}
	else
		cout << s[d.first][d.second] << '\n';
}