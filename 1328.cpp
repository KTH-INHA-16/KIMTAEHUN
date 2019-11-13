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
	// �ʱⰪ ���� 1,1,1 �϶� 1
	for (int i = 1; i <= n-1; i++)
	// i�� n-1�� ������ i+1�� ���� ó���ϱ� ����
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
				//�¿쿡 ������ �����̴� ���� �� �ܰ踦 �߰� ���ָ� ��
				d[i + 1][j][k] += d[i][j][k] * (i - 1);
				//�¿츦 ������ �͵��� ���ܰ�*����-1�� ��� ����
				d[i + 1][j][k] %= mod;
			}
		}
	}
	//bottom-up���� Ǭ��
	cout << d[n][l][r] << '\n';
}