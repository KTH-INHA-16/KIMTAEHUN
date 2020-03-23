#include <iostream>
#include <queue>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;

priority_queue<int, vector<int>, less<int>> max_h;
priority_queue<int, vector<int>, greater<int>>min_h;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t, n;
	cin >> t;
	while (t--)
	{
		cin >> n;
		if (max_h.empty())
			max_h.push(n);
		else if (max_h.size() == min_h.size())
			max_h.push(n);
		else
			min_h.push(n);

		if (!max_h.empty() && !min_h.empty() && !(max_h.top() <= min_h.top()))
		{
			int a = max_h.top();
			int b = min_h.top();
			max_h.pop();
			min_h.pop();
			max_h.push(b);
			min_h.push(a);
		}
		cout << max_h.top()<<'\n';
	}
}
