#include <iostream>
#include <cstdio>
using namespace std;

bool check[100020];
long long a, b;

int main()
{
	cin >> a >> b;
	for (long long i = 2; i*i <= b; i++)
	{
		long long start = i * i - a%(i*i);
		// �ּڰ��� i^2�� �������� ���ִ� ����?
		//���۰��� ã������ �׷��� �ʱ갪�� �۾�����.
		if (start == i * i)
			start = 0;
		for (long long j = start; j <= b - a; j += i * i)
		{
			check[j] = true;
		}
	}
	int ans = 0;
	for (int i = 0; i <= b - a; i++)
	{
		if (check[i]==0)
			ans += 1;
	}
	cout << ans << '\n';
}