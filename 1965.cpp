#include<iostream>
using namespace std;
#include<algorithm>
//LIS 알고리즘 사용 
//시간 복잡도 O(nlogn)
int arr[40001];
int LIS[40001];
int n, ans = 0, Size = 1;
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	LIS[1] = arr[1];
	int tmp;
	for (int i = 2; i <= n; i++)
	{
		if (LIS[Size] < arr[i])
		{
			Size++;
			LIS[Size] = arr[i];
			continue;
		}
		tmp = lower_bound(LIS + 1, LIS + Size + 1, arr[i]) - LIS;
		LIS[tmp] = arr[i];
	}
	ans = Size;
	cout << ans << "\n";
	return 0;
}