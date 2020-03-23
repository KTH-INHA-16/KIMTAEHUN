#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

int main()
{
	double n;
	cin >> n;
	printf("%.6f\n", double((n*n)*M_PI));
	printf("%.6f\n", double(2 * n*n));
}