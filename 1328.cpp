#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n, l, r;
long long d[101][101][101];
long long mod = 1000000007LL;

int main()
{
	cin >> n >> l >> r;
	d[1][1][1] = 1LL;
	// 초기값 설정 1,1,1 일땐 1
	for (int i = 1; i <= n-1; i++)
	// i가 n-1인 이유는 i+1을 연산 처리하기 때문
	{
		for (int j = 1; j <= l; j++)
		{
			for (int k = 1; k <= r; k++)
			{
				if (j + 1 <= l)
				{
					d[i + 1][j + 1][k] += d[i][j][k];
					d[i + 1][j + 1][k] %= mod;
				}
				if (k + 1 <= r)
				{
					d[i + 1][j][k+1] += d[i][j][k];
					d[i + 1][j ][k+1] %= mod;
				}
				//좌우에 한층씩 더보이는 것은 전 단계를 추가 해주면 됨
				d[i + 1][j][k] += d[i][j][k] * (i - 1);
				//좌우를 제외한 것들은 전단계*높이-1로 계산 가능
				d[i + 1][j][k] %= mod;
			}
		}
	}
	//bottom-up으로 푼다
	cout << d[n][l][r] << '\n';
}