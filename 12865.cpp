#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int n, k, w, v;
pair<int, int> a[101];
int m[100001];
//��ǰ�� �����϶� �ִ��� ��ġ��?

int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].first >> a[i].second;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = k; j >= 1; j--)
		{
			if (a[i].first <= j)
			{
				m[j] = max(m[j], m[j - a[i].first] + a[i].second);
				//max���� m[j]�� �׳� �������� ���
				//max���� m[j-a[i].first]+a[i].second
				//�� �ش� ��ǰ�� �������� ���Կ��� ���繰ǰ�� ��ġ�� ���Ѱ�
			}
		}
	}
	cout << m[k]  << '\n';
}