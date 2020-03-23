#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int > c[501];
int cache[501];
int n;

int lis()
//lis문제 lis문제인 이유?
//전깃줄은 늘어나면서 연결되어야 꼬이지 않는데
//부분적으로 늘어나지않는 부분을 찾아야 하는 문제
{
	int idx = 0;
	int length = 0;
	cache[idx] = c[0].second;
	for (int i = 1; i < n; i++)
	{
		if (cache[idx] < c[i].second)
			cache[++idx] = c[i].second;
		else
		{
			int idx2 = lower_bound(cache, cache + idx, c[i].second) - cache;
			cache[idx2] = c[i].second;
			length++;
		}
	}
	return length;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> c[i].first >> c[i].second;
	}
	sort(c, c + n);
	cout << lis() << '\n';
}