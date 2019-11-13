#include <iostream>
using namespace std;

long long a[500000];
long long b[500000];

long long ans2(int s, int e)
{
	if (s == e)
		return 0;
	int mid = (s + e) / 2;
	long long ans = ans2(s, mid) + ans2(mid + 1, e);
	int i = s;
	int j = mid + 1;
	int k = 0;
	while (i <= mid || j <= e)
	{
		if (i <= mid && (j > e || a[i] <= a[j]))
			b[k++] = a[i++];
		else
		{
			ans += (long long)(mid - i + 1);
			b[k++] = a[j++];
		}
	}
	for (int i = s; i <= e; i++)
	{
		a[i] = b[i - s];
	}
	return ans;

}

int main(void)
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cout<<ans2(0, n-1)<<endl;
}