#include <iostream>
using namespace std;

int main(void)
{
	int n, m, k;
	cin >> n >> m >> k;
	int ans = 0;
	while (true)
	{
		if (n + m >= k + 3&&n>=2&&m>=1)
		{
			n -= 2;
			m--;
			ans++;
		}
		else
			break;
	}
	cout << ans << endl;
}