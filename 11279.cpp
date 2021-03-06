#include <functional>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main()
{
	int n;
	priority_queue<int, vector<int>, greater<int>> q;
	//<자료형,구현체,비교 연산자>
	cin >> n;

	while (n--)
	{
		int x;
		cin >> x;

		if (x == 0)
		{
			cout << (q.empty() ? 0 : q.top()) << '\n';
			if (!q.empty())
			{
				q.pop();
			}
		}
		else {
			q.push(x);
		}
	}

	return 0;
}