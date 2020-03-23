#include <iostream>
using namespace std;

int m[1000001];
int n;

int main()
{
	cin >> n;
	m[1] = 1;
	m[2] = 2;
	for (int i = 3; i <= n; i++)
	{
		m[i] = (m[i - 2] + m[i - 1]) % 15746;
	}
	//bottom-up ��� A(n) = A(n-1) + A(n-2)
	//������� �ݺ����� ���� bottom-up �ϼ�
	cout <<m[n] << '\n';
}