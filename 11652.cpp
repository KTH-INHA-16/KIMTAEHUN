#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

pair<long long int, long long int> c[1000100];

bool cmp(const pair<long long int, long long int>&a, const pair<long long int, long long int>&b)
{
	if (a.first == b.first)
		return a.second < b.second;
	else 
		return a.first > b.first;
}

int main(void)
{
	std::ios::sync_with_stdio(false);
	long long int n;
	cin >> n;
	vector <long long int> d(n);
	for (long long int i = 0; i < n; i++)
	{
		cin >> d[i];
	}

	sort(d.begin(), d.end());
	long long int save = d[0];
	c[0].first = 1;
	c[0].second = d[0];
	long long int index = 0;

	for (long long int i = 1; i < n; i++)
	{
		if (save == d[i])
			c[index].first++;
		else
		{
			save = d[i];
			index++;
			c[index].first = 1;
			c[index].second = d[i];
		}
	}
	sort(c, c + index+1,cmp);
	cout << c[0].second <<endl;
}