#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	string a, b, c, d;
	cin >> a >> b >> c >> d;
	
	a = a + b;
	c = c + d;
	long long n1 = stoll(a);
	long long n2 = stoll(c);
	cout << n1 + n2<<endl;
}