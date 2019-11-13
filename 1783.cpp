#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	int m, n;
	cin >> m >> n;

	if (m == 1)
	{
		cout << 1 << endl;
	}
	else if (m == 2)
	{
		cout << min(4, (n + 1) / 2)<<endl;
	}
	else if (m>= 3)
	{
		if (n >= 7)
			cout << n - 2 << endl;
		else
			cout << min(4, n)<<endl;
	}

}