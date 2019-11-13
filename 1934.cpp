#include <iostream>
using namespace std;

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a%b);
}

int gcl(int a, int b)
{
	return gcd(a, b)*(a / gcd(a, b))*(b / gcd(a, b));
}

int main(void)
{
	int n;
	cin >> n;
	
	while (n--)
	{
		int a, b;
		cin >> a >> b;
		
		printf("%d\n", gcl(a, b));
	}
}