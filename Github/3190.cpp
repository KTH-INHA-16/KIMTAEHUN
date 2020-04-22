#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <cstring>
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, char> pic;
pii d[] = { {0,1},{1,0},{0,-1},{-1,0} };

int a[101][101];
bool c[101][101];
int n, k, l;

//덱을 이용한 구현 문제 
//꽤나 까다롭고 방향 구현을 잘 해야하며
// 큐에 어떤 순서로 들어가고 나가고 확장되는지 잘 파악해야함

int main()
{
	cin >> n >> k;
	for (int i = 0; i < k; i++)
	{
		int x, y;
		cin >> y >> x;
		a[y - 1][x - 1] = 1;
	}
	cin >> l;
	deque<pic> m;
	for (int i = 0; i < l; i++)
	{
		int x; char y;
		cin >> x >> y;
		m.push_back(pic(x, y));
	}
	deque<pii> s;
	s.push_back(pii(0, 0));
	c[0][0] = true;
	int idx = 0;
	int ans = 0;
	while (1)
	{
		ans++;
		pii before = s.back();
		pii cnt = pii(s.back().first, s.back().second);
		cnt.first += d[idx].first;
		cnt.second += d[idx].second;
		if (c[cnt.first][cnt.second] || !(cnt.first >= 0 && cnt.first < n && cnt.second >= 0 && cnt.second < n))
		{
			cout << ans << '\n';
			break;
		}
		c[cnt.first][cnt.second] = true;
		s.push_back(cnt);
		if (a[cnt.first][cnt.second])
			a[cnt.first][cnt.second] = 0;
		else
		{
			pii tail = s.front();
			c[tail.first][tail.second] = false;
			s.pop_front();
		}
		if (m.size()&&ans == m.front().first)
		{
			if (m.front().second == 'D')
				idx = (idx + 1) % 4;
			else
				idx = (idx + 3) % 4;
			m.pop_front();
		}
	}
}