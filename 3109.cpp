#include <iostream>
#include <vector>
#include <string>
using namespace std;

int r, c;
string a[10001];
bool check[10001][501];
int dx[] = { 1,1,1 };
int dy[] = { -1,0,1 };

bool dfs(int y, int x)
{
	check[y][x] = true;
	if (x == c - 1)
		return true;
	for (int i = 0; i < 3; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (nx >= 0 && nx < c&&ny >= 0 && ny < r)
		{
			if (!check[ny][nx] && a[ny][nx] == '.')
			{
				bool flag = dfs(ny, nx);
				if (flag)
					return flag;
				//��ΰ� �����ϸ� true ��ȯ
			}
		}
	}
	return false;
	//�� �������� false�� ������ �ش� ��ΰ� ���� ����
}

int main()
{
	cin >> r >> c;
	for (int i = 0; i < r; i++)
	{
		cin >> a[i];
	}
	int ans = 0;

	for (int i = 0; i < r; i++)
		ans += dfs(i,0);

	cout << ans << '\n';
	return 0;

}