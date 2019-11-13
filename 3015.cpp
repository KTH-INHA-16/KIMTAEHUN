#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

long long a[500001];
long long ans;

int main()
{
	int n;
	cin >> n;
	for (int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	stack <pair<int,int>> s;
	for (int i = 0; i < n; i++)
	{
		pair<int, int> p = { a[i],1 };
		//Ű�� ���� ��츦 pair�� �߰�
		while (!s.empty())
		{
			if (s.top().first <= a[i])
			{
				ans += (long long)s.top().second;
				//Ű�� ���� ��� �߰�
				if (s.top().first == a[i])
					//���� ������
					//���� �ε��� �߰�
				{
					p.second += s.top().second;
				}
				s.pop();
			}
			else
			{
				break;
			}
		}
		if (!s.empty())
			//������� ������ 1�߰�
			//������ ���� �����ִ� ����� a���� Ű�� ū�� �� ����� �� �� �ֱ� ����
			ans += 1LL;
		s.push(p);
			//�ٽ� push
	}
	cout << ans << '\n';
}