#include <iostream>
#include <functional>
#include <queue>
#include <vector>
#include <math.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		if (x == 0)
		{
			if (!pq.empty())
			{
				auto p = pq.top();
				cout << p.second << '\n';
				pq.pop();
			}
			else
				cout << 0 << '\n';
		}
		else
			pq.push(make_pair(abs(x),x));
	}
}