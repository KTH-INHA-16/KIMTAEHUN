#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int cnt;

int main(void)
{
	int n;
	vector <vector<int>> v;
	while (true)
	{
		cin >> n;
		if (n == 0)
		{
			break;
		}
		vector<int> e(n);
		v.push_back(e);
		for (int i = 0; i < n; i++)
		{
			cin >> v[cnt][i];
		}
		cnt++;
	}

	for (int i = 0; i < cnt; i++)
	{
		int a = v[i].size();
		vector <int> d(a,1);
		for (int i = 0; i < 6; i++)
			d[i] = 0;
		do {
			for (int j = 0; j < a; j++)
			{
				if (d[j] == 0)
					cout << v[i][j] << ' ';
			}
			cout << '\n';
		} while (next_permutation(d.begin(), d.end()));

		cout << '\n';
	}
	
}