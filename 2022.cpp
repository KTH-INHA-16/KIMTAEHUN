#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main(void)
{
	double x, y, c;
	cin >> x >> y >> c;

	double low = 0;
	double high = min(x, y);
	double ans = 0;
	while (high - low > 0.000001)
	{
		double mid = (high + low) / 2.0;
		double cnt = 0;
		double h1 = sqrt(x*x - mid * mid);
		double h2 = sqrt(y*y - mid * mid);
		cnt = (h1*h2) / (h1 + h2);
		if (cnt >= c)
		{
			ans = mid;
			low = mid;
		}
		else
			high = mid;
		
	}
	printf("%.3lf\n", ans);
}