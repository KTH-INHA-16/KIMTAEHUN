#include <iostream>
#include <cstring>
#include <queue>
#include <deque>
using namespace std;

typedef pair<int, int> pii;
int n, l;
int a[101][101];
int ans;

//구현을 물어보는 문제 상황에 따라 분기를 나누고 계산하는 것을 연습해보는 문제
//1 -> 2, 2 -> 1 일때 분기가 다르다는 것을 명심하자
//조건이 생각보다 까다롭다.

bool check(int idx,int direction)
{
	if (direction == 0)
	{
		vector<pii> v;
		int height = a[idx][0];
		int len = 1;
		for (int i = 1; i < n; i++)
		{
			if (height == a[idx][i])
				len++;
			else
			{
				v.push_back(pii(len,height));
				height = a[idx][i];
				len = 1;
			}
			if (i == n - 1)
				v.push_back(pii(len, height));
		}
		if (v.size() != 1)
		{
			int cnt = v[0].first;
			int height = v[0].second;
			for (int i = 1; i < v.size(); i++)
			{
				if (height - v[i].second == -1)
				{
					if (cnt < l)
						return false;
					else
					{
						cnt = v[i].first;
						height = v[i].second;
					}
				}
				else if (height - v[i].second == 1)
				{
					if (v[i].first < l)
						return false;
					else
					{
						v[i].first -= l;
						cnt = v[i].first;
						height = v[i].second;
					}
				}
				else
					return false;
			}
		}
	}
	else
	{
		vector<pii> v;
		int height = a[0][idx];
		int len = 1;
		for (int i = 1; i < n; i++)
		{
			if (height == a[i][idx])
				len++;
			else
			{
				v.push_back(pii(len, height));
				height = a[i][idx];
				len = 1;
			}
			if (i == n - 1)
				v.push_back(pii(len, height));
		}
		if (v.size() != 1)
		{
			int cnt = v[0].first;
			int height = v[0].second;
			for (int i = 1; i < v.size(); i++)
			{
				if (height - v[i].second == -1)
				{
					if (cnt < l)
						return false;
					else
					{
						cnt = v[i].first;
						height = v[i].second;
					}
				}
				else if (height - v[i].second == 1)
				{
					if (v[i].first < l)
						return false;
					else
					{
						v[i].first -= l;
						cnt = v[i].first;
						height = v[i].second;
					}
				}
				else
					return false;
			}
		}
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> l;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	for (int i = 0; i < n; i++)
		if (check(i, 0))
			ans++;
	for (int i = 0; i < n; i++)
		if (check(i, 1))
			ans++;
	cout << ans << '\n';
}