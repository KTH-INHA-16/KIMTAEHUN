#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	int arr[10000];
	int count=0;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string a;
		cin >> a;
		if (a[1] == 'u')
		{
			int num;
			cin >> num;
			arr[count] = num;
			count++;
		}
		else if (a[1] == 'o'&&a[0]=='p')
		{
			if (count > 0)
			{
				cout << arr[count-1] << endl;
				count--;
				if (count < 0)
					count = 0;
			}
			else
			{
				cout << "-1" << endl;
			}
		}
		else if (a[1] == 'i')
		{
			cout << count << endl;
		}
		else if (a[1] == 'm')
		{
			if (count == 0)
				cout << "1" << endl;
			else
				cout << "0" << endl;
		}
		else if (a[0] == 't'&&a[1]=='o')
		{
			if (count > 0)
			{
				cout << arr[count-1] << endl;
			}
			else
				cout << "-1" << endl;
		}
	}
}