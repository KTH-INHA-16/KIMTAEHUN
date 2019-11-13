#include <iostream>
#include <string>
using namespace std;

int alp[26];
int main(void)
{
	string s;
	cin >> s;
	int n = s.size();
	while (n--)
	{
		alp[s[n] - 97]++;
	}
	int i = 0;
	while (i<25)
	{
		cout << alp[i] << " ";
		i++;
	}
	cout << alp[25] << endl;
}