#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int ans;
int n, m,r,c,d;
int a[51][51];
pair<int, int> dir[] = { {0,-1},{1,0},{0,1},{-1,0} };
//Tlqkf ���� ��� �ȹٷ� ����
//��Ī�� ���õ� ���� ������
//�ܼ��� ���� dfs,bfs��� ����

void clean(int x, int y, int cnt)
{
	if (a[y][x] == 0)
	{
		a[y][x] = 2;
		ans++;
	}
	for (int i = 0; i < 4; i++)
	{
		int nd = (cnt + 3 - i) % 4;
		int nx = x + dir[nd].first;
		int ny = y + dir[nd].second;
		if (ny < 0 || nx < 0 || ny >= n || nx >= m)
			continue;
		if (a[ny][nx] == 0)
			clean(nx, ny, nd);
	}
		int nd = (cnt + 2) % 4;
		int nx = x + dir[nd].first;
		int ny = y + dir[nd].second;
		if (a[ny][nx] == 1)
		{
			cout << ans << '\n';
			exit(0);
		}
		clean(nx, ny, cnt);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	cin >> r >> c >> d;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	clean(c, r, d);

}