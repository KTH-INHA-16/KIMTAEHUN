#include <iostream>
#include <string>
using namespace std;

int n, m;
int a[51][4];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string tmp;
		cin >> tmp;
		for (int j = 0; j < tmp.size(); j++)
		{
			if (tmp[j] == 'A')
				a[j][0] += 1;
			else if (tmp[j] == 'C')
				a[j][1] += 1;
			else if (tmp[j] == 'G')
				a[j][2] += 1;
			else
				a[j][3] += 1;
		}
	}
	int ans = 0;
	string dans = "";
	for (int i = 0; i < m; i++)
	{
		int idx = 0, cnt = 0;
		for (int j = 0; j < 4; j++)
		{
			if (a[i][j] > cnt)
			{
				idx = j;
				cnt = a[i][j];
			}
		}
		ans += (n - cnt);
		switch (idx)
		{
		case 0:
			dans += 'A';
			break;
		case 1:
			dans += 'C';
			break;
		case 2:
			dans += 'G';
			break;
		case 3:
			dans += 'T';
			break;
		}
	}
	cout << dans << '\n' << ans << '\n';
}