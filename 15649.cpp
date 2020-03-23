#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int m, n;
int a[9];
bool check[9];

void func(int cnt)
{
	if (cnt == m)
	{
		for (int i = 0; i < m; i++)
			cout << a[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (!check[i])
		{
			check[i] = true;
			a[cnt] = i;
			func(cnt + 1);
			check[i] = false;
			// 해당 경우 검사후 다시 그 자식으로 돌아가기!!
		}
	}
}

int main()
{
	cin >> n >> m;
	func(0);
}