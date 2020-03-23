#include <iostream>
#include <string>
using namespace std;
//��Ʈ��ŷ -> dfs�� ���� �ϸ鼭 ������������ 
//����Ǽ��� ���ܸ� �ϰ� ���� ���� �Ѿ�� ���

int n;
string ans;

void dfs(char c, int cnt)
{
	if (cnt - 1 == n)
	{
		cout << ans << '\n';
		//������ ���� �ϴ� ���
		//���� ���� �����¼��� �������� ���
		exit(0);
		//exit(0) -> �Լ���ü�� ���� ����
		//return -> �� �ܰ��� �Լ� ����
	}
	ans += c;
	//���� ����
	for (int i = 1; i <= cnt / 2; i++)
		//���� �˻� �κ�
		//1/2���������� �˻�
	{
		string a = ans.substr(cnt - i, i);
		//1/2�̻� ������ ����
		string b = ans.substr(cnt - i * 2, i);
		//1/2���� ������ ����
		if (a == b)
			//������ ���� ���
		{
			ans.erase(cnt - 1);
			//�ش� ���� ����
			return;
		}
	}
	for (int i = 1; i <= 3; i++)
		dfs(i + '0', cnt + 1);
	//���ڿ� �߰� -> dfs(����)
	ans.erase(cnt - 1);
	//cnt - 1�ڸ� �������� �ʴ� ���
}

int main()
{
	cin >> n;
	for (int i = 1; i <= 3; i++)
		dfs(i + '0', 1);
	//��� ��쿡 �ش��ؼ� ����
	return 0;
}