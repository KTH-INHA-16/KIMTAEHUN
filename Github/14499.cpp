#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, m,k,x,y;
int a[21][21];
int roll[1001];
int dice[7];
int tmp[7];
pair<int, int> d[] = { {},{0,1},{0,-1},{-1,0},{1,0} };

//그림을 잘 파악하자 -> 구현,시뮬레이션은 최대한 간단하게 생각하는게 답

void save()
{
	for (int i = 1; i <= 6; i++)
		tmp[i] = dice[i];
}

int main()
{
	cin >> n >> m >> x >> y>>k;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	for (int i = 0; i < k; i++)
		cin >> roll[i];	
	
	for (int i = 0; i < k; i++)
	{
		if (0 <= x + d[roll[i]].first && x + d[roll[i]].first < n && 0 <= y + d[roll[i]].second && y + d[roll[i]].second < m)
		{
			save();
			x = x + d[roll[i]].first;
			y = y + d[roll[i]].second;
			if (roll[i] == 1)
			{
				dice[1] = tmp[4];
				dice[3] = tmp[1];
				dice[4] = tmp[6];
				dice[6] = tmp[3];
			}
			else if (roll[i] == 2)
			{
				dice[1] = tmp[3];
				dice[3] = tmp[6];
				dice[4] = tmp[1];
				dice[6] = tmp[4];
			}
			else if (roll[i] == 3)
			{
				dice[1] = tmp[5];
				dice[2] = tmp[1];
				dice[5] = tmp[6];
				dice[6] = tmp[2];
			}
			else
			{
				dice[1] = tmp[2];
				dice[2] = tmp[6];
				dice[5] = tmp[1];
				dice[6] = tmp[5];
			}
			if (a[x][y] == 0)
				a[x][y] = dice[6];
			else
			{
				dice[6] = a[x][y];
				a[x][y] = 0;
			}
			cout << dice[1] << '\n';
		}
		else
			continue;
	}
}