#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	int a[20001];
	int n;
	cin >> n;
	int front=10000;
	int back=10000;
	int size = 0;
	int pcount = 0;
	int n1;
	while (n--)
	{
		string s;
		cin >> s;
		if (s == "push_front")
		{
			if (pcount >= 1)
			{
				front--;
			}
			cin >> n1;
			a[front] = n1;
			pcount++;
			size++;
		}
		else if (s == "push_back")
		{
			if (pcount >= 1)
			{
				back++;
			}
			cin >> n1;
			a[back] = n1;
			pcount++;
			size++;
		}
		else if (s == "pop_front")
		{
			if (size!=0)
			{
				cout << a[front] << endl;
				if (size != 1)
				{
					front++;
				}
				pcount--;
				size--;
			}
			else
				cout << "-1" << endl;
		}
		else if (s == "pop_back")
		{
			if (size != 0)
			{
				cout << a[back] << endl;
				if (size != 1)
				{
					back--;
				}
				pcount--;
				size--;
			}
			else
				cout << "-1" << endl;
		}
		else if (s == "size")
		{
			cout << size << endl;
		}
		else if (s == "empty")
		{
			if (size != 0)
			{
				cout << "0" << endl;
			}
			else
			{
				cout << "1" << endl;
			}
		}
		else if (s == "front")
		{
			if (size != 0)
			{
				cout << a[front] << endl;
			}
			else
			{
				cout << "-1" << endl;
			}
		}
		else
		{
			if (size != 0)
			{
				cout << a[back] << endl;
			}
			else
			{
				cout << "-1" << endl;
			}
		}
	}
}