#include <iostream>
#include <cstring>
#include <string>
using namespace std;

const long long MOD = 100000;

int n;
string a;
string open = "({[";
string close = ")}]";
long long d[201][201];

long long go(int s, int e)
{
	if (s > e)
		return 1;
	long long &ans = d[s][e];
	if (ans != -1)
		return ans;
	ans = 0;
	for (int i = s + 1; i <= e; i+=2)
		//2개씩 추가 하는 이유?
		// 중간에 2개씩 더 페어링이 가능하기 때문
	{
		for (int j = 0; j < open.size(); j++)
		{
			if (a[s] == open[j] || a[s] == '?')
				//열린괄호 나오면?
			{
				if (a[i] == close[j] || a[i] == '?')
					//바로 닫힌 괄호 검사
				{
					long long tmp;
					tmp = go(s + 1, i - 1)*go(i + 1, e);
					//출발+1 부터 k-1까지 
					//k+1 부터 끝 까지
					//2개를 남기는 이유?
					//그 중간이 페어가 될 수 있기 때문
					ans += tmp;
					if (ans >= MOD)
						ans = MOD + ans % MOD;
				}
			}
		}
	}
	return ans;
}

int main()
{
	cin >> n>>a;
	memset(d, -1, sizeof(d));
	long long ans = go(0, n - 1);
	if (ans >= MOD)
	{
		printf("%05lld\n", ans % MOD);
	}
	else
		cout << ans << '\n';
}