#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	string s;
	cin >> s;

	vector<string> v;
	for (int i = 0; i < s.length(); i++)
		v.push_back(s.substr(i, s.length()));

	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << "\n";

	return 0;

}