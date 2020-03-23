#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int x, y, w, h;
	cin >> x >> y >> w >> h;
	int ans = 0;
	ans = min(w - x, x);
	ans = min(ans, min(y, h - y));
	cout << ans << '\n';
}