#include <iostream>
using namespace std;

int p[1000000];
int pn = 0;
bool c[1000001];

int main(void)
{
	int m, n;
	cin >> m >> n;
	for (long long i = 2; i <= n; i++) {
		if (c[i] == false) {
			p[pn++] = i;
			for (long long j = i * i; j <= n; j += i) {
				c[j] = true;
			}
		}
		if (i >= m)
			if (c[i] == false)
				printf("%d\n", i);
	}

}