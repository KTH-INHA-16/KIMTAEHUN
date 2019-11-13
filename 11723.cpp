#include <iostream>
#include <string>
#define endl '\n'
using namespace std;

int ans;

int main(void)
{
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	int n;
	cin >> n;
	while (n--)
	{
		string a;
		cin >> a;
		if (a == "add")
		{
			int num;
			cin >> num;
			ans |= (1 << num);
		}
		else if (a == "remove")
		{
			int num;
			cin >> num;
			ans &= ~(1 << num);
		}
		else if (a == "check")
		{
			int num;
			cin >> num;
			int check = ans & (1 << num);
			if (check == 0)
			{
				cout << 0 << endl;
			}
			else
			{
				cout << 1 << endl;
			}
		}
		else if (a == "toggle")
		{
			int num;
			cin >> num;
			int check = ans & (1 << num);
			if (check == 0)
			{
				ans |= (1 << num);
			}
			else
			{
				ans &= ~(1 << num);
			}
		}
		else if (a == "all")
		{
			for (int i = 1; i <= 20; i++)
			{
				int check = ans & (1 << i);
				if (check == 0)
				{
					ans |= (1 << i);
				}
			}
		}
		else if (a == "empty")
		{
			ans = 0;
		}

	}
}