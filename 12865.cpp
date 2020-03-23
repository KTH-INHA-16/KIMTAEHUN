#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int n, k, w, v;
pair<int, int> a[101];
int m[100001];
//물품의 무게일때 최대의 가치는?

int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].first >> a[i].second;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = k; j >= 1; j--)
		{
			if (a[i].first <= j)
			{
				m[j] = max(m[j], m[j - a[i].first] + a[i].second);
				//max에서 m[j]는 그냥 가져가는 경우
				//max에서 m[j-a[i].first]+a[i].second
				//는 해당 물품을 들고기전의 무게에서 현재물품의 가치를 더한것
			}
		}
	}
	cout << m[k]  << '\n';
}