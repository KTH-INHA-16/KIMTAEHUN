#include <iostream>
using namespace std;

//1���� �������� �����
// �������� �Է°� ���� ��� ������ x
// �ƴѰ��� ����� ����
int n;

int find()
{
	int cnt = 1;
	while (1)
	{
		int copy = cnt;
		int sum = cnt;
		while (copy)
		{
			sum += copy % 10;
			copy /= 10;
		}
		if (cnt == n || sum == n)
			break;
		cnt++;
		//���Ʈ ������ �⺻
	}
	return cnt;
}

int main()
{

	cin >> n;
	int ans = find();
	if (ans == n)
		cout << 0 << '\n';
	else
		cout << ans << '\n';
}