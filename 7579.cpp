#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N, M;
int m[101];
int c[101];
int memo[101][10001];

int dp(int idx, int cost)
{
	if (idx >= 100)
		return 0;
	if (memo[idx][cost] != -1)
		return memo[idx][cost];
	memo[idx][cost] = dp(idx + 1, cost);
	if (c[idx] <= cost)
		memo[idx][cost] = max(memo[idx][cost], m[idx] + dp(idx + 1, cost - c[idx]));
	return memo[idx][cost];
}

int main()
{
	memset(memo, -1, sizeof(memo));
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> m[i];
	for (int i = 0; i < N; i++)
		cin >> c[i];
	int ans = 0;
	while (1)
	{
		if (dp(0, ans) >= M)
		{
			cout << ans << '\n';
			break;
		}
		ans += 1;
	}
}