#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int inf = 98765432;
//���ǿ� ��ȸ
//��� ���ƿ��� ���õ� ����
//��Ʈ ����ŷ���� ǥ������ 
//�湮 ���� 1 �̹湮 0
//�ּұ� ������ �ʱ갪 ������ ���Ѵ��.
int w[17][17];
int m[17][1 << 16];
int n;

int dp(int start, int visited)
{
	if (m[start][visited] != -1)
		return m[start][visited];

	//��� �湮 �Ͽ����� -> ù��° ���÷� ���ư���
	if (visited == (1<<n) - 1)
	{
		if (w[start][0] != 0)
			return w[start][0];
		else
			return inf;
	}

	m[start][visited] = inf;
	for (int i = 0; i < n; i++)
	{
		if (w[start][i] && !(visited&(1 << i)))
		{
			int to_visit = visited | (1 << i);
			m[start][visited] = min(m[start][visited], dp(i, to_visit) + w[start][i]);
		}
	}
	return m[start][visited];
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> w[i][j];
	memset(m, -1, sizeof(m));
	cout << dp(0, 1) << '\n';
}