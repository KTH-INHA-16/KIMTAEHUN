#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<pair<pair<int,int>,int>> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i].first.first >> v[i].first.second;
		v[i].second = 1;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				continue;
			else if (v[i].first.first < v[j].first.first&&v[i].first.second < v[j].first.second)
				//���Ʈ ����-> ������ �� ��������
				//�����Կ� Ű�� �Ѵ� �۾ƾ� ����� �ö󰣴ٴ�
				//���̵� �����ؼ� 2�� for���� ���� �ѹ����ذ�
			{
				v[i].second ++;
			}
		}
	}
	for (int i = 0; i < n; i++)
		cout << v[i].second << ' ';
	cout << '\n';

}