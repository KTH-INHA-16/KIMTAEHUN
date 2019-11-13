#include <iostream>
using namespace std;

int a[100000];
int b[100000];
int c[100001];
int root;

void solve(int is, int ie, int ps, int pe)
{
	if (is > ie || ps > pe)
		return;
	int root = b[pe];
	printf("%d ", root);
	int p = c[root];
	int left = p - is;
	solve(is, p - 1, ps, ps + left - 1);
	solve(p + 1, ie, ps + left, pe - 1);
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
	}
	for (int i = 0; i < n; i++)
	{
		c[a[i]] = i;
	}
	solve(0, n - 1, 0, n - 1);
}