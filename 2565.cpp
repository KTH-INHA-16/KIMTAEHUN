#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int > c[501];
int cache[501];
int n;

int lis()
//lis���� lis������ ����?
//�������� �þ�鼭 ����Ǿ�� ������ �ʴµ�
//�κ������� �þ���ʴ� �κ��� ã�ƾ� �ϴ� ����
{
	int idx = 0;
	int length = 0;
	cache[idx] = c[0].second;
	for (int i = 1; i < n; i++)
	{
		if (cache[idx] < c[i].second)
			cache[++idx] = c[i].second;
		else
		{
			int idx2 = lower_bound(cache, cache + idx, c[i].second) - cache;
			cache[idx2] = c[i].second;
			length++;
		}
	}
	return length;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> c[i].first >> c[i].second;
	}
	sort(c, c + n);
	cout << lis() << '\n';
}