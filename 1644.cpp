#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int d[10000011];
vector <int> a;
int main()
{
	int n;
	cin >> n;
	for (int i = 2; i <= 10000001; i++)
	{
		d[i] = i;
	}
	for (int i = 2; i <= sqrt(10000001); i++)
	{
		if (d[i]==0)
			//소수가 아닌것들 건너 뛰기
			continue;
		for (int j = i+i; j <= 10000001; j += i)
		{
			d[j] = 0;
			//i의 배수들은 모두 삭제
		}
	}
	//에라토스테네스의 체 -> 소수 찾기 최적화
	for (int i = 2; i <= 10000001; i++)
	{
		if (d[i] != 0)
			a.push_back(d[i]);
	}
	auto p = a.end() - 1;
	int left = 0, right = 0;
	int sum = a[0];
	int ans = 0;
	while (left <= right && a[right] <= n)
	{
		if (sum < n)
		{
			right += 1;
			sum += a[right];
		}
		else if (sum == n)
		{
			ans += 1;
			right += 1;
			sum += a[right];
		}
		else if (sum > n)
		{
			sum -= a[left];
			left += 1;
		}
	}
	cout << ans << '\n';
}