#include <iostream>
using namespace std;

int d[1000000];

int makeone(int n)
{
	if (n == 1)
		return 0;
	if (d[n] > 0)
		return d[n];
	d[n] = makeone(n - 1) + 1;
	if (n % 2 == 0)
	{
		int temp = makeone(n / 2) + 1;
		if (d[n] > temp)//ÃÖ¼Ú°ªÃ£±â
			d[n] = temp;
	}
	if (n % 3 == 0)
	{
		int temp = makeone(n / 3) + 1;
		if (d[n] > temp)//ÃÖ¼Ú°ª Ã£±â
			d[n] = temp;
	}
	return d[n];
}

int main(void)
{
	int N;
	cin >> N;
	cout << makeone(N) << endl;
}

