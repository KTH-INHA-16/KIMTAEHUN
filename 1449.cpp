#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a[1001];
bool b[1001];

int main()
{
	int n, l;
	cin >> n >> l;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a+n);
	//������ ���� �տ� �ִ� ����������
	//���ʴ�� �������� ���̸� �ּ������� �������Ҽ� �ֱ�
	//����
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (!b[a[i]])
			//bool �迭�� ���� �ش� ������ �������ߴ��� Ȯ��
		{
			for (int j = a[i]; j < min(a[i] + l, 1001); j++)
				//greedy ������� ���ʴ�� ������ ���ĵ� �ǹǷ�
				b[j] = true;
			ans += 1;
		}
	}
	cout << ans << '\n';
}