#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector <int>v(n);
	vector <int>v2(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		v2[i] = v[i];
	}

	if (next_permutation(v2.begin(), v2.end()) == false)
	{
		cout << "-1"<<endl;
	}
	else
	{
		next_permutation(v.begin(), v.end());
		for (int i = 0; i < n; i++)
		{
			cout << v[i] << " ";
		}
		cout << endl;
	}
}