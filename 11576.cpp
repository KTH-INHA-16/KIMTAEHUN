#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	int a, b;
	cin >> a >> b;
	int m;
	cin >> m;
	vector<int> v1;
	vector<int> v2;

	while (m--)
	{
		int k;
		cin >> k;
		v1.push_back(k);
	}
	unsigned long long int p = 0;
	unsigned long long int a1 = 1;
	for (int i = v1.size()-1; i >=0; i--)
	{
		p += a1 * v1[i];
		a1 *= a;
	}

	while (p > 0)
	{
		int r = p % b;
		v2.push_back(r);
		p = p / b;
	}
	unsigned long long size = v2.size();
	for (unsigned long long i = size-1; i >= 0; i--)
	{
		if (i == 0)
		{
			cout << v2[i];
			break;
		}
		else
			cout << v2[i] << " ";
	}
	cout << endl;

}