#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

vector<int> p[1001];
bool check[1001];

void dfs(int x)
{
	check[x] = true;
	for (int i = 0; i < p[x].size(); i++)
	{
		int y = p[x][i];
		if (check[y] == false)
		{
			dfs(y);
		}
	}
}

int main(void)
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		p[a].push_back(b);
		p[b].push_back(a);
	}

	int c = 0;

	for (int i = 1; i <= n; i++)
	{
		if (check[i] == false)
		{
			dfs(i);
			c++;
		}
	}

	cout << c << endl;

}