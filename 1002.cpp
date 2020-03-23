#include <iostream>
#include <math.h>
#define _USE_MATH_DEFINES
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		double x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		if (x1 == x2 && y1 == y2)
		{
			if (r1 == r2)
				cout << -1 << '\n';
			else
				cout << 0 << '\n';
		}
		else
		{
			double l = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
			double round = r1 > r2 ? r1 : r2;
			double min_round = r1 > r2 ? r2 : r1;
			if (round == l)
			{
				cout << 2 << '\n';
			}
			else if (l < round)
			{
				if (l + min_round == round)
					cout << 1 << '\n';
				else if (l + min_round < round)
					cout << 0 << '\n';
				else
					cout << 2 << '\n';
			}
			else
			{
				if (l == round + min_round)
				{
					cout << 1 << '\n';
				}
				else if (l > round + min_round)
					cout << 0 << '\n';
				else
					cout << 2 << '\n';
			}
		}
	}
}