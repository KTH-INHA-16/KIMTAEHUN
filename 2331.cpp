#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

long long check[300000];

int next(int a, int p)
{
	int sum = 0;
	int plus = a%10;
	int count = p;
	while (a > 0)
	{
		while (count>1)
		{
			plus *= (a % 10);
			count--;
		}
		sum += plus;
		count = p;
		a /= 10;
		plus = a % 10;
	}
	
	return sum;
}

int length(int a, int p, int cnt)//dfs¹æ½Ä
{
	if (check[a] != 0)
	{
		return check[a] - 1;
	}
	check[a] = cnt;
	int b = next(a, p);
	return length(b, p, cnt + 1);
}

int main(void)
{
	int a, p;
	cin >> a >> p;

	int ans = length(a, p, 1);
	cout << ans << endl;
	
}