#include <iostream>
using namespace std;

int a[20];//������ ����
int n, s;
int ans;//��� ������ �������� ���

void find(int idx, int sum)
{
	if (idx == n)//����Լ� ȣ��� ������ �ε����� ����������
	{
		if (sum == s)//�̶������� ���� s�� �������
		{
			ans += 1;//�κ����� �� ����
		}
		return;//����Լ� ����κ�
	}
	//��Ʈ��ŷ
	// ���� �����ְ� idx�� 1����
	find(idx +1 , sum + a[idx]);
	//�ε��� �ϳ����� + ���� �߰�
	//�׳� idx�� ������
	find(idx + 1, sum);
	//�ܼ� �ε��� ����->��Ʈ��ŷ �ٽ�
}

int main(void)
{
	cin >> n >> s;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	find(0, 0);//0���� ����
	if (s == 0)//0�� ��찡 ī��Ʈ�� 1�� �� �����ϹǷ�
		ans -= 1;//1�� ����
	cout << ans << endl;
}