#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector <int> v1(n);
	vector <int> v2(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v1[i];
		v2[i] = v1[i];
	}
	if (prev_permutation(v2.begin(), v2.end()) == false)
	{
		cout << "-1\n";
	}
	else
	{
		prev_permutation(v1.begin(), v1.end());
		for (int i = 0; i < n; i++)
		{
			cout << v1[i] << " ";
		}
		cout << "\n";
	}
}