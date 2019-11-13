#include <iostream>
using namespace std;

void solve(int n, int x, int y)
{
	if (n == 0)
		return;
	solve(n - 1, x, 6 - x - y);
	printf("%d %d\n", x, y);
	solve(n - 1, 6 - x - y, y);

}

int main(void)
{
	int n;
	cin >> n;
	printf("%d\n", (1<<n)-1);
	solve(n, 1, 3);
}