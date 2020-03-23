#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int inf = 98765432;
//외판원 순회
//출발 돌아오기 관련된 문제
//비트 마스킹으로 표현가능 
//방문 했음 1 미방문 0
//최소기 때문에 초깃값 설정을 무한대로.
int w[17][17];
int m[17][1 << 16];
int n;

int dp(int start, int visited)
{
	if (m[start][visited] != -1)
		return m[start][visited];

	//모두 방문 하였으면 -> 첫번째 도시로 돌아가라
	if (visited == (1<<n) - 1)
	{
		if (w[start][0] != 0)
			return w[start][0];
		else
			return inf;
	}

	m[start][visited] = inf;
	for (int i = 0; i < n; i++)
	{
		if (w[start][i] && !(visited&(1 << i)))
		{
			int to_visit = visited | (1 << i);
			m[start][visited] = min(m[start][visited], dp(i, to_visit) + w[start][i]);
		}
	}
	return m[start][visited];
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> w[i][j];
	memset(m, -1, sizeof(m));
	cout << dp(0, 1) << '\n';
}