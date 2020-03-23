#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;

const int inf = 1000000001;

int n, m;
int a[100001];
int group[100001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int r = 1;
	for (int i = 1; i*i <= n; i++)
		r = i;
	for (int i = 0; i < n; i++)
	{
		if (i%r == 0)
			group[i / r] = a[i];
		else
			group[i / r] = min(a[i], group[i / r]);
	}
	while (m--)
	{
		int start, end;
		cin >> start >> end;
		start -= 1;
		end -= 1;
		int ans = a[start];
		int g1 = start / r;
		int g2 = end / r;
		if (g1 == g2)
			//같은 그룹일때
			for (int i = start; i <= end; i++)
				ans = min(ans, a[i]);
		else
		{
			// 서로 다른 그룹일때
			// 시작그룹에 속함, 끝그룹에 속함, 사이에 속함
			while (true)
			{
				ans = min(ans, a[start]);
				start += 1;
				if (start % r == 0)
					break;
			}
			while (true)
			{
				ans = min(ans, a[end]);
				end -= 1;
				if (end % r == r - 1)
					break;
			}
			for (int i = start / r; i <= end / r; i++)
				ans = min(ans, group[i]);
		}
		cout << ans << '\n';
	}
}