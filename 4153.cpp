#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	while (1)
	{
		vector<int> a(3);
		cin >> a[0] >> a[1] >> a[2];
		if (a[0] == 0 && a[1] == 0 && a[2] == 0)
			return 0;
		sort(a.begin(), a.end());
		if (a[0]*a[0]+a[1]*a[1] == a[2]*a[2])
		{
			cout << "right\n";
		}
		else
			cout << "wrong\n";

	}
}