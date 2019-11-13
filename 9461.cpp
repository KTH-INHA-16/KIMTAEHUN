#include <iostream>
using namespace std;

long long d[101];
int main(void)
{
	int n;
	cin >> n;

	d[1] = 1;
	d[2] = 1;
	d[3] = 1;
	d[4] = 2;
	d[5] = 2;
	while (n--)
	{
		int k;
		cin >> k;

		for (int i = 6; i <= k; i++)
		{
			d[i] = d[i - 1] + d[i - 5];
		}

		cout << d[k]<<endl;
		
	}
}