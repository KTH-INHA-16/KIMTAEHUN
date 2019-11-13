#include <iostream>
using namespace std;

int arr[10002];

int main(void)
{
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int max = 0;
	int n1 = n;
	while (n--)
	{
		int k;
		cin >> k;
		arr[k]++;
	}
	
	for (int i = 1; i <= 10000; i++)
	{
		while (arr[i] > 0)
		{
			printf("%d\n", i);
			arr[i]--;
		}
	}
}