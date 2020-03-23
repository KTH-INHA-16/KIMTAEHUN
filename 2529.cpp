#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string sign;

bool valid(vector<int> &v)
{
	for (int i = 0; i < sign.size(); i++)
	{
		if (sign[i] == '<'&&v[i] > v[i + 1])
			return false;
		else if (sign[i] == '>'&&v[i] < v[i + 1])
			return false;
	}
	return true;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		char tmp;
		cin >> tmp;
		sign += tmp;
	}
	vector<int> maxVal(n+1);
	vector<int>	minVal(n+1);
	for (int i = 0; i <= n; i++)
	{
		maxVal[i] = 9 - i;
		minVal[i] = i;
	}
	while (1)
	{
		if (valid(maxVal))
			break;
		prev_permutation(maxVal.begin(), maxVal.end());
	}
	while (1)
	{
		if (valid(minVal))
			break;
		next_permutation(minVal.begin(), minVal.end());
	}
	for (int i = 0; i < maxVal.size(); i++)
		cout << maxVal[i];
	cout << '\n';
	for (int i = 0; i < minVal.size(); i++)
		cout << minVal[i];
	cout << '\n';
}