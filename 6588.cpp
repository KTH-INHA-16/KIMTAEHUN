#include <iostream>
using namespace std;

int p[1000001];
bool c[1000001];
int pn = 0;

int main(void)
{
	long long count = 100001;
	for (unsigned long long i = 2; i <= 1000001; i++)
	{
		if (c[i] == false)
		{
			p[pn++] = i;
			for (unsigned long long j = i * i; j <= 1000001; j += i)
				c[j] = true;
		}
	}

	count = 1000000;
	while (count--)
	{
		int n;
		cin >> n;
		if (n == 0)
			break;
		int ck = 1;
		while (true)
		{
			int a, b;
			a = p[ck];
			if (c[n-a] != true)
			{
				b = n - a;
				printf("%d = %d + %d\n", n, a, b);
				break;
			}
			if (a >= n / 2)
			{
				printf("Goldbach's conjecture is wrong.\n");
				break;
			}
			ck++;
		}
	}
}