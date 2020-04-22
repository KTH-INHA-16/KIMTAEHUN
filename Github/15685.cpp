#include <iostream>
#include <vector>
#include <queue>
#include <deque>
using namespace std;

//전세대는 현재세대에서 회전하면서 뒤에 붙여주면 이때까지의 커브가 완성

bool check[101][101];
pair<int, int> dir[] = { {0,1},{-1,0},{0,-1},{1,0} };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x, y, g, d;
		cin >> x >> y >> d >> g;
		vector<int> cnt;
		cnt.push_back(d);
		//현재 점에 대한 방향 추가
		for (int j = 0; j < g; j++)
			//이전 세대의 커브(방향) 추적
		{
			vector<int> tmp = cnt;
			//복사
			for (int k = tmp.size() - 1; k >= 0; k--)
				//뒤에서부터 회전 복사
				//뒤에서 부터 하는이유는 j세대의 첫번째값은 j-1세대에서
				//인덱스에서 회전 한 값임
				cnt.push_back((tmp[k]+1)%4);
		}
		check[y][x] = true;
		for (int i = 0; i < cnt.size(); i++)
		{
			y += dir[cnt[i]].first;
			x += dir[cnt[i]].second;
			if (0 <= x && x <= 100 && 0<= y && y <= 100)
				check[y][x] = true;
		}
		
	}
	int ans = 0;
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
			if (check[i][j] && check[i + 1][j] && check[i][j + 1] && check[i + 1][j + 1])
				ans++;
	}
	cout << ans << '\n';

}