#include <iostream>
#include <vector>
using namespace std;

int n, num, del, root;
int ans;
vector<int> v[51];

void dfs(int s)
{
	if (s == del)
		return;
	int cnt = 0;
	for (int i = 0; i<v[s].size(); i++)
	{
		if (v[s][i] == del)
			continue;
		dfs(v[s][i]);
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
		if (num != -1)
			v[num].push_back(i);
		else
			root = i;
	}
	cin >> del;
	v[del].clear();
	dfs(root);
	cout << ans << '\n';
}