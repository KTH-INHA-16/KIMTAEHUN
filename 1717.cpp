#include <iostream>
#include <algorithm>
using namespace std;

int parent[1000001];

int find(int x)
{
	if (x == parent[x])
		return x;
	else
		return parent[x] = find(parent[x]);
}

void Union(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x != y)
	{
		parent[y] = x;
	}
}


int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i <= n; i++)
	{
		parent[i] = i;
	}
	for (int i = 0; i < m; i++)
	{
		int how,c,d;
		cin >> how>>c>>d;
		if (how == 0)
		{
			Union(c,d);
		}
		else if(how == 1)
		{
			c = find(c);
			d = find(d);
			if (c==d)
			{
				cout << "yes\n";
			}
			else
			{
				cout << "no\n";
			}
		}
	}
}