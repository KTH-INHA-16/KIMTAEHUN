#include <iostream>
#include <math.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

unsigned long long a, b, c;

unsigned long long go(long long a, long long b)
{
	if (b == 0)
		return 1;
	else if (b == 1)
		return a%c;
	else if (b % 2 == 0)
	{
		unsigned long long tmp = go(a, b / 2)%c;
		return tmp%c * tmp%c;
	}
	else
	{
		return a * go(a, b - 1)%c;
	}
}

int main()
{
	cin >> a >> b >> c;
	cout <<(unsigned long long) go(a, b) << '\n';
}