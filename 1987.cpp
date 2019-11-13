#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector <bool> check(26, false);
int ans;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

void go(vector<string>&board, vector<bool>&check, int x, int y, int cnt)
{
	if (cnt > ans)
		ans = cnt;
	for (int k = 0; k < 4; k++)
	{
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size())
		{
			if (check[board[nx][ny] - 'A'] == false)
			{
				check[board[nx][ny] - 'A'] = true;
				go(board, check, nx, ny, cnt + 1);
				check[board[nx][ny] - 'A'] = false;
			}
		}
	}
}

int main(void)
{
	int n, m;
	cin >> n >> m;
	vector<string> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	check[a[0][0] - 'A'] = true;
	ans = 1;
	go(a, check, 0, 0, ans);
	cout << ans << '\n';
}