#include <iostream>
#include <cstdio>
using namespace std;

bool check[100020];
long long a, b;

int main()
{
	cin >> a >> b;
	for (long long i = 2; i*i <= b; i++)
	{
		long long start = i * i - a%(i*i);
		// 최솟값의 i^2를 나머지를 빼주는 이유?
		//시작값을 찾기위해 그러면 초깃값이 작아진다.
		if (start == i * i)
			start = 0;
		for (long long j = start; j <= b - a; j += i * i)
		{
			check[j] = true;
		}
	}
	int ans = 0;
	for (int i = 0; i <= b - a; i++)
	{
		if (check[i]==0)
			ans += 1;
	}
	cout << ans << '\n';
}