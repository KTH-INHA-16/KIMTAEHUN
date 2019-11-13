#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;

double dist(double x1, double y1, double z1, double x2, double y2, double z2) {
	return sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1) + (z2 - z1)*(z2 - z1));
}

int main()
{
	double ax, ay, az;
	double bx, by, bz;
	double cx, cy, cz;
	cin >> ax >> ay >> az >> bx >> by >> bz>>cx>>cy>>cz;

	double dx = bx - ax;
	double dy = by - by;
	double dz = bz - az;

	double left = 0.0;
	double right = 1.0;
	double m = 0;
	while (true)
	{
		if (abs(right - left) < 1e-9)
		{
			m = (left + right) / 2;

		}
		double m1 = left + (right - left) / 3;
		double m2 = right - (right - left) / 3;
		double mx1 = ax + dx * m1;
		double my1 = ay + dy * m1;
		double mz1 = az + dz * m1;
		double mx2 = ax + dx * m2;
		double my2 = ay + dy * m2;
		double mz2 = az + dz * m2;
		double ms1 = dist(mx1, my1, mz1, cx, cy, cz);
		double ms2 = dist(mx2, my2, mz2, cx, cy, cz);
		if (m1 > m2)
		{
			left = m1;
		}
		else
		{
			right = m2;
		}
	}
	double x0 = ax + m * dx;
	double y0 = ay + m * dy;
	double z0 = az + m * dz;
	double ans = dist(x0, y0, z0, cx, cy, cz);
	cout << fixed << setprecision(10) << ans << endl;
	return 0;
}