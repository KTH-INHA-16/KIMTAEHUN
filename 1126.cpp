#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int max_differ = 500000*50;

int n;
int a[51];
int d[51][250001];

int go(int b, int differ)
{
	if (differ > 250000)
		return -max_differ;
	//���̰� �ִ뺸�� �������� �� �������� ���ϰ� ó��
	//�ᱹ ������� ��Ȳ���� ���� �����
	if (b == n)
	{
		if (differ == 0)
			return 0;
		else
			return -max_differ;
		//�� else�� ���� max�Լ��� �������� ���� ���ϰ� ����ֱ� ���ؼ� ���δ�
	}
	int &ans = d[b][differ];
	if (ans != -1)
		return ans;
	ans = go(b + 1, differ);
	//�׳� ����������� ���� ġ�� ���
	ans = max(ans, go(b + 1, differ + a[b]));
	//���� ���� ���� �װ� ���� ���
	if (a[b]>differ)
	{
		ans = max(ans, differ + go(b + 1, a[b] - differ));
		//����ž�� �� ū���
		//���� - ū + �� ���� ������
	}
	else
	{
		ans = max(ans, a[b] + go(b + 1, differ - a[b]));
		//0�̿��� ž�� �� Ŀ������ ���
		//ū - ���� + �� ������ �� ����
	}
	return ans;
}



int main(void)
{
	cin >> n;
	memset(d, -1, sizeof(d));
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int ans = go(0, 0);
	if (ans == 0)
		cout << -1 << '\n';
	else
		cout << ans << '\n';
}