#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	int e = 1, s = 1, l = 1;
	long long ans = 1;
	while (true)
	{
		if (e == a && s == b && l == c)
		{
			cout << ans << '\n';
			return 0;
		}
		e++;
		s++;
		l++;
		ans++;
		if (e > 15)
			e = 1;
		if (s > 28)
			s = 1;
		if (l > 19)
			l = 1;
	}
}