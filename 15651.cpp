#include <iostream>
using namespace std;

int n, m;
bool check[9];
int a[9];

void go(int cnt)
{
	if (cnt == m)
	{
		for (int i = 0; i < cnt; i++)
		{
			cout << a[i] << ' ';
		}
		cout << '\n';
		return ;
	}
	for (int i = 1; i <= n; i++)
	{
		check[i] = false;
		if (!check[i])
		{
			check[i] = true;
			a[cnt] = i;
			go(cnt+1);
			check[i] = false;
		}
	}
}

int main()
{
	cin >> n >> m;
	go(0);
}