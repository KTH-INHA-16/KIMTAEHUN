#include <iostream>
#include <vector>
#include <queue>
#include <deque>
using namespace std;

//������� ���缼�뿡�� ȸ���ϸ鼭 �ڿ� �ٿ��ָ� �̶������� Ŀ�갡 �ϼ�

bool check[101][101];
pair<int, int> dir[] = { {0,1},{-1,0},{0,-1},{1,0} };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x, y, g, d;
		cin >> x >> y >> d >> g;
		vector<int> cnt;
		cnt.push_back(d);
		//���� ���� ���� ���� �߰�
		for (int j = 0; j < g; j++)
			//���� ������ Ŀ��(����) ����
		{
			vector<int> tmp = cnt;
			//����
			for (int k = tmp.size() - 1; k >= 0; k--)
				//�ڿ������� ȸ�� ����
				//�ڿ��� ���� �ϴ������� j������ ù��°���� j-1���뿡��
				//�ε������� ȸ�� �� ����
				cnt.push_back((tmp[k]+1)%4);
		}
		check[y][x] = true;
		for (int i = 0; i < cnt.size(); i++)
		{
			y += dir[cnt[i]].first;
			x += dir[cnt[i]].second;
			if (0 <= x && x <= 100 && 0<= y && y <= 100)
				check[y][x] = true;
		}
		
	}
	int ans = 0;
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
			if (check[i][j] && check[i + 1][j] && check[i][j + 1] && check[i + 1][j + 1])
				ans++;
	}
	cout << ans << '\n';

}