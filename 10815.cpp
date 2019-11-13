#include <iostream>
#include <algorithm>
using namespace std;

int a1[500001];
int ans[500001];
int cnt;

int main(void)
{
	int n1,n2;
	cin >> n1;
	for (int i = 0; i < n1; i++)
	{
		cin >> a1[i];
	}
	sort(a1, a1 + n1);
	cin >> n2;
	for (int i = 0; i < n2; i++)
	{
		int num;
		cin >> num;
		int left = 0;
		int right = n1 - 1;
		while (left <= right)
		{
			int mid = (left + right) / 2;
			if (a1[mid] == num)
			{
				cout << 1 << ' ';
				cnt = 1;
				break;
			}
			else if (a1[mid] > num)
			{
				right = mid -1;
			}
			else if (a1[mid] < num)
			{
				left = mid + 1;
			}
		}
		if (cnt != 1)
		{
			cout << 0 << ' ';
			cnt = 0;
		}
		cnt = 0;
	}
	cout << '\n';

}