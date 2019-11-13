#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int a, b;
		cin >> a >> b;
		vector<long long> fibo;
		fibo.push_back(0);
		fibo.push_back(1);
		fibo.push_back(1);
		int n = 3;
		while (1)
		{
			fibo.push_back(fibo[n - 2] + fibo[n - 1] % b);
			if (fibo[n - 1] % b == 0 && fibo[n] % b == 1)
				break;
				n += 1;
		}
		cout <<a<<' '<< n-1 << '\n';
	}
}