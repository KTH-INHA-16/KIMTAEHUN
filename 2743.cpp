#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main(void)
{
	string s;
	cin >> s;
	int i = 0,count=0;
	while (s[i] != NULL)
	{
		count++;
		i++;
	}
	cout << count << endl;
}