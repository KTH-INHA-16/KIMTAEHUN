#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int a[10];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int left;
		cin >> left;
		for (int j = 0; j < n; j++)
		{
			if (left == 0 && a[j] == 0)
			{
				a[j] = i + 1;
				break;
			}
			else if (a[j] == 0)
				left--;
		}
	}
	for (int i = 0; i < n; i++)
		cout << a[i] << ' ';
	cout << '\n';
}