#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string a, b;
int ans = 987654321;

void differ()
{
	for (int i = 0; i <= b.length() - a.length(); i++)
	{
		int cnt = 0;
		for (int j = 0; j < a.length(); j++)
		{
			if (a[j] != b[j + i])
				cnt += 1;
		}
		ans = min(ans, cnt);
	}
}

int main()
{
	cin >> a >> b;
	differ();
	cout << ans << '\n';
}