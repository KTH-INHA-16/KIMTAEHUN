#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int a[21][21];
int s1[20];
int s2[21];
bool check[21];
int min_val = 987654321;

void go(int start,int cnt)
//파라미터 갯수 생각!! -> 어느 선수를 스타팅 맴버로 할것인가?
{
	if (cnt == n / 2)
	{
		int tmp = 0;
		for (int i = 0; i < n; i++)
		{
			if (!check[i])
			{
				s2[tmp] = i;
				tmp++;
			}
		}
		int sum1=0, sum2=0;
		for (int i = 0; i < cnt; i++)
		{
			for (int j = i + 1; j < cnt; j++)
			{
				sum1 += (a[s1[i]][s1[j]] + a[s1[j]][s1[i]]);
				sum2 += (a[s2[i]][s2[j]] + a[s2[j]][s2[i]]);
			}
		}
		int dif;
		dif = abs(sum1 - sum2);
		min_val = min(dif, min_val);
		return;
	}
	for (int i = start; i < n; i++)
	{
		if (!check[i])
		{
			check[i] = true;
			s1[cnt] = i;
			go(i,cnt + 1);
			check[i] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	}
	go(0,0);
	cout << min_val << '\n';
}