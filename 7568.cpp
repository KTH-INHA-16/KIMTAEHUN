#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<pair<pair<int,int>,int>> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i].first.first >> v[i].first.second;
		v[i].second = 1;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				continue;
			else if (v[i].first.first < v[j].first.first&&v[i].first.second < v[j].first.second)
				//브루트 포스-> 조건을 잘 생각하자
				//몸무게와 키가 둘다 작아야 등수가 올라간다는
				//아이디어에 착안해서 2중 for문에 의해 한번에해결
			{
				v[i].second ++;
			}
		}
	}
	for (int i = 0; i < n; i++)
		cout << v[i].second << ' ';
	cout << '\n';

}