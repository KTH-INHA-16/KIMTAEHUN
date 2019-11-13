#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	int a[20000];
	int n;
	cin >> n;
	int count = 0;
	int front = 0;
	int back = 0;
	int size = 0;
	for (int i = 1; i <= n; i++)
	{
		string c;
		cin >> c;
		if (c[1] == 'u')
		{
			int b;
			cin >> b;
			a[count] = b;
			back = count;
			count++;
			size++;
		}
		else if (c[1] == 'o')
		{
			if (size <= 0)
				cout << "-1" << endl;
			else
			{
				cout << a[front] << endl;
				front++;
				if(size>0)
					size--;
			}
		}
		else if (c[1] == 'i')
		{
			cout << size << endl;
		}
		else if (c[1] == 'm')
		{
			if (size == 0)
			{
				cout << "1" << endl;
			}
			else
			{
				cout << "0" << endl;
			}
		}
		else if (c[1] == 'r')
		{
			if (size == 0)
				cout << "-1" << endl;
			else
				cout << a[front] << endl;
		}
		else if (c[1] == 'a')
		{
			if (size == 0)
				cout << "-1" << endl;
			else
				cout << a[back] << endl;
		}
	}
}