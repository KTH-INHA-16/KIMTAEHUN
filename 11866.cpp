#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	queue<int> q;
	queue<int> ans;
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		q.push(i);
	for (int i = 0; i < n; i++)
	{
		if(q.size()>1)
		for (int j = 0; j < k-1; j++)
		{
			int tmp = q.front();
			q.pop();
			q.push(tmp);
		}
		if (!q.empty())
		{
			int cnt = q.front();
			ans.push(cnt);
			q.pop();
		}
		else
			break;
	}
	cout << '<';
	while (!ans.empty())
	{
		cout << ans.front();
		ans.pop();
		if (ans.size() == 0)
			break;
		cout << ", ";
	}
	cout << ">\n";
}