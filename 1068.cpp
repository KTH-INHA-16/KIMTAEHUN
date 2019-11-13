#include<iostream>
#include <vector>
using namespace std;

int n, num, root;
int ans;
vector<int> v[51];

void dfs(int r)
{
	if (num == r)
		return;
	int cnt=0;
	for (int i = 0; i < v[r].size(); i++)
	{
		if (v[r][i] == num)
			continue;
		dfs(v[r][i]);
		cnt += 1;
	}
	if (cnt == 0)
		ans += 1;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		if (num == -1)
			root = i;
		else
			v[num].push_back(i);
	}
	cin >> num;
	v[num].clear();
	dfs(root);
	cout << ans << '\n';
}