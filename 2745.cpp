#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	string a;
	long long b;
	cin >> a>>b;
	int s = a.size();
	long long ans = 0;
	long long b2 = 1;
	while (s--)
	{
		int n;
		if (a[s] >= 'A')
			n = a[s] - 'A' + 10;
		else
			n = a[s] - '0';
		ans += n * b2;
		b2 *= b;
	}

	cout << ans << endl;
}