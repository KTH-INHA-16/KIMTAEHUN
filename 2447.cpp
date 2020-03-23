#include <iostream>
using namespace std;
int cnt;

void solve(int n, int x, int y)
{
	if (n == 0)
		return;
	cnt++;
	solve(n - 1, x, 6 - x - y);
	printf("%d %d\n", x, y);
	solve(n - 1, 6 - x - y, y);

}
void solve2(int n, int x, int y)
{
	if (n == 0)
		return;
	cnt++;
	solve2(n - 1, x, 6 - x - y);
	solve2(n - 1, 6 - x - y, y);

}

int main(void)
{
	int n;
	cin >> n;
	solve2(n, 1, 3);
	printf("%d\n", cnt);
	solve(n, 1, 3);
}