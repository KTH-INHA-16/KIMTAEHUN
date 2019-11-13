#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector <int>vc;
int main()
{
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		vc.push_back(num);
	}
	vector<int> lis (n + 1, 1000001);
	for (int i = 0; i < n; i++)
	{
		auto it = lower_bound(lis.begin(), lis.end(), vc[i]) - lis.begin();
		lis[it] = vc[i];
	}
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (lis[i] != 1000001)
			cnt++;
	}
	cout << cnt;

	return 0;
}