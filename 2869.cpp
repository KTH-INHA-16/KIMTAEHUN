#include <iostream>
using namespace std;

int main()
{
	int a, b, v;
	cin >> a >> b >> v;
	int s = 0;
	int e = (v + a) / (a - b);
	int ans = 0x7fffffff;
	while (s <= e)
	{
		int m = (s + e) / 2;
		int h = (a*m) - (b*(m - 1));
		if (h >= v)
		{
			ans = ans > m ? m : ans;
			e = m - 1;
		}
		else
			s = m + 1;
	}
	cout << ans << '\n';
	//�̺� Ž�� ������ ���ٰ���
	//�����̰� ���ǿ� ���� ������ �ϼ���? ���� �ؼ�����
}