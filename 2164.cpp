#include <iostream>
#include <deque>
using namespace std;

int main()
{
	int n;
	cin >> n;
	deque<int> d;
	for (int i = n; i >= 1; i--)
	{
		d.push_back(i);
	}
	while (d.size() != 1)
	{
		d.pop_back();
		int tmp = d.back();
		d.pop_back();
		d.push_front(tmp);
	}
	cout << d.front() << '\n';
}