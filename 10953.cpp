#include <iostream>
using namespace std;

int main(void)
{
	char a[3];
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		/*
		getline(cin, a, ',');
        getline(cin, b);
        cout << stoi(a) + stoi(b) << '\n';	//a,b는 string type 이게더 간편한것 같다........
		*/
		for (int j = 0; j < 3; j++)
		{
			cin >> a[j];
		}
		int b = a[0]-48;
		int c = a[2]-48;
		cout << b + c << endl;
	}
}