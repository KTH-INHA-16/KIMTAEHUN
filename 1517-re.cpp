#include <iostream>
using namespace std;

long long a[500000];
long long b[500000];

long long solve(int start, int end)
{
	if (start == end)
		return 0;
	int mid = (start + end) / 2;
	long long ans = solve(start, mid) + solve(mid + 1, end);
	int i = start;
	int j = mid+1;
	int k = 0;
	while (i <= mid || j <= end)
	{
		if (i <= mid && (j > end || a[i] <= a[j]))
			b[k++] = a[i++];
		else
		{
			ans += (long long)(mid - i + 1);
			b[k++] = a[j++];
		}
	}

	for (int i = start; i <= end; i++)
	{
		a[i] = b[i - start];
	}

	return ans;

}

int main(void)
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	printf("%d\n", solve(0, n - 1));
}