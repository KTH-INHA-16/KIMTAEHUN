#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector <int> v(9);
	vector <int> v2(9);
	for (int i = 0; i < 9; i++)
	{
		cin >> v[i];
		v2[i] = v[i];
	}
	sort(v2.begin(), v2.end());
	cout << v2[8] << '\n';
	for (int i = 0; i < 9; i++)
	{
		if (v2[8] == v[i])
			cout << i + 1 << '\n';
	}
	
}