#include <iostream>
using namespace std;

int main(void)
{
	int a;
	int n;
	int min;
	int max;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a;
		if (i == 1)
		{
			max = a;
			min = a;
		}
		if (min > a)
			min = a;
		if (max < a)
			max = a;
	}
	cout << min << " " << max<<endl;
}