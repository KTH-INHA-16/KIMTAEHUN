#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	vector <int> v(9);
	int sum = 0;
	for (int i = 0; i < 9; i++)
	{
		cin >> v[i];
		sum += v[i];
	}
	sum -= 100;
	int s1;
	int s2;
	for (int i = 0; i < 9; i++)
	{
		for (int j = i+1; j < 9; j++)
		{
			if (( v[i] + v[j]) ==sum)
			{
				s1 = i;
				s2 = j;
			}
		}
	}
	v[s1] = 0;
	v[s2] = 0;
	sort(v.begin(), v.end());
	for (int i = 0; i < 9; i++)
	{
		if (v[i] != 0)
		{
			cout << v[i] << endl;
		}
	}
}