#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

int n, w;
pair<int, int> pos[1005];
int m[1005][1005];
int c[1005][1005];

int dist(pair<int, int>& a, pair<int, int>& b)
{
	return abs(a.first - b.first) + abs(a.second - b.second);
}


int dp(int x, int y)
{
	int cnt = max(x, y) + 1;
	if (cnt == w + 2)
		return 0;
	int& ret = m[x][y];
	if (ret != -1)
		return ret;
	ret = dp(cnt, y) + dist(pos[x], pos[cnt]);
	int yret = dp(x, cnt) + dist(pos[y], pos[cnt]);
	if (yret < ret)
	{
		ret = yret;
		c[x][y] = 1;
	}
	return ret;

}

int main()
{
	cin >> n >> w;
	for (int i = 2; i < w + 2; i++)
		cin >> pos[i].first >> pos[i].second;
	pos[0] = { 0,0 }; pos[1] = { n,n };
	memset(m, -1, sizeof(m));
	cout << dp(0, 1) << '\n';
	for (int x = 0, y = 1; max(x, y) + 1 < w + 2;)
	{
		cout << c[x][y] + 1 << '\n';
		if (c[x][y])
			y = max(x, y) + 1;
		else
			x = max(x, y) + 1;
	}
}