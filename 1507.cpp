#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set>
using namespace std;

int dist[21][21];
int inf = 1000000000;
int check[21][21];

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> dist[i][j];
		}
	}
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			if (i == k)
				continue;
			for (int j = 1; j <= n; j++)
			{
				if (i == j)
					continue;
				if (k == j)
					continue;
				//i==k, i==j, k==j 3��츦 �����ؾ���
				if (dist[i][j] > dist[i][k] + dist[k][j])
					//�ּڰ��� ���ŵǴ� ���?
				{
					cout << "-1\n";
					//Ʋ�����
					return 0;
				}
				if (dist[i][j] == dist[i][k] + dist[k][j])
					//�ּڰ��� �������°��
				{
					check[i][j] = true;
					//i->j�� �Ⱦ��±�
				}
			}
		}
	}
	//�÷��̵� �ͼ� �˰���
	int ans = 0;

	for(int i=1;i<=n;i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (check[i][j] == false)
			{
				ans += dist[i][j];
			}
		}
	}
	cout << ans/2 << '\n';
}