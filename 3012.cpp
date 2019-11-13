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
		//2���� �߰� �ϴ� ����?
		// �߰��� 2���� �� ���� �����ϱ� ����
	{
		for (int j = 0; j < open.size(); j++)
		{
			if (a[s] == open[j] || a[s] == '?')
				//������ȣ ������?
			{
				if (a[i] == close[j] || a[i] == '?')
					//�ٷ� ���� ��ȣ �˻�
				{
					long long tmp;
					tmp = go(s + 1, i - 1)*go(i + 1, e);
					//���+1 ���� k-1���� 
					//k+1 ���� �� ����
					//2���� ����� ����?
					//�� �߰��� �� �� �� �ֱ� ����
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