#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

vector<pair<int, int>> v;
int r, c, k;
deque<int> col[110];
deque<int> row[110];
int map[110][110];
int num[101];

/*
��¥ ������ �ϸ� �Ǵ� ���������ϴ�.

R�� C ���길 �� �����ϸ� �Ǵµ� �Ʒ��� ���� ������ �ڵ带 �ۼ��ϸ� �˴ϴ�.

1. �� ��/�࿡ ��Ÿ���� ������ ����Ƚ���� ���ϰ�

2. vector<pair<int, int>> v[MAX]�� �����Ͽ� �� ��/�ึ�� ��Ÿ���� {������ ����Ƚ��, ����}�� ������ �����ϵ��� �մϴ�.

3. ������ �迭�� ��� 0���� �ʱ�ȭ�ϰ�

4. ������ �� ��/�ึ�� �������� ������ �����մϴ�.

5. ���������� ������ �� ��/�ึ�� ���ĵ� ������� ������ ��/�࿡ ����, ������ ����Ƚ�� ������ �־��ָ� �˴ϴ�.(��, ������ ���Ҹ��� ������ �迭 �� ĭ�� ��ƸԴ´�.)
*/

bool cmp(pair<int, int>& a, pair<int, int>& b)
{
	if (a.second == b.second)
		return a.first < b.first;
	else
		return a.second < b.second;
}

void rfunc()
{
	int max_row = 0;
	for (int i = 0; i < 100; i++)
	{
		if (row[i].size() == 0)
			break;
		memset(num, 0, sizeof(num));
		v.clear();
		for (int j = 0; j < row[i].size(); j++)
			if(row[i][j]>0)
				num[row[i][j]]++;
		for (int j = 1; j <= 100; j++)
			if (num[j] > 0)
				v.push_back({ j,num[j] });
		sort(v.begin(), v.end(), cmp);
		max_row = max(max_row,(int)v.size() * 2);
		if (max_row > 100)
			max_row = 100;
		row[i].clear();
		for (int j = 0; j < v.size() ; j++)
		{
			if (row[i].size() == 100)
				break;
			row[i].push_back(v[j].first);
			row[i].push_back(v[j].second);
		}
	}
	for (int i = 0; i < 100; i++)
	{
		if (row[i].size() != 0)
		{
			while (row[i].size() < max_row)
				row[i].push_back(0);
		}
		else
			break;
	}
	for (int i = 0; i < 100; i++)
	{
		if (col[i].size() > 0)
			col[i].clear();
		else
			break;
	}
	for (int i = 0; i < 100; i++)
	{
		if (row[i].size() == 0)
			break;
		for (int j = 0; j < row[i].size(); j++)
		{
			col[j].push_back(row[i][j]);
		}
	}
	for (int i = 0; i < 100; i++)
	{
		if (row[i].size() == 0)
			break;
		for (int j = 0; j < row[i].size(); j++)
		{
			map[i][j] = row[i][j];
		}
	}
}

void cfunc()
{
	int max_col = 0;
	for (int i = 0; i < 100; i++)
	{
		if (col[i].size() == 0)
			break;
		memset(num, 0, sizeof(num));
		v.clear();
		for (int j = 0; j < col[i].size(); j++)
			if (col[i][j] > 0)
				num[col[i][j]]++;
		for (int j = 1; j <= 100; j++)
			if (num[j] > 0)
				v.push_back({ j,num[j] });
		sort(v.begin(), v.end(), cmp);
		max_col = max(max_col, (int)v.size() * 2);
		if (max_col > 100)
			max_col = 100;
		col[i].clear();
		for (int j = 0; j < v.size(); j++)
		{
			if (col[i].size()==100)
				break;
			col[i].push_back(v[j].first);
			col[i].push_back(v[j].second);
		}
	}
	for (int i = 0; i < 100; i++)
	{
		if (col[i].size() != 0)
		{
			while (col[i].size() < max_col)
				col[i].push_back(0);
		}
		else
			break;
	}
	for (int i = 0; i < 100; i++)
	{
		if (row[i].size() > 0)
			row[i].clear();
		else
			break;
	}
	for (int i = 0; i < 100; i++)
	{
		if (col[i].size() == 0)
			break;
		for (int j = 0; j < col[i].size(); j++)
		{
			row[j].push_back(col[i][j]);
		}
	}
	for (int i = 0; i < 100; i++)
	{
		if (row[i].size() == 0)
			break;
		for (int j = 0; j < row[i].size(); j++)
		{
			map[i][j] = row[i][j];
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> r >> c >> k;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			int x;
			cin >> x;
			row[i].push_back(x);
			col[j].push_back(x);
			map[i][j] = x;
		}
	int ans = 0;
	while (1)
	{
		if (map[r - 1][c - 1] == k)
		{
			cout << ans << '\n';
			return 0;
		}
		if (ans > 100)
		{
			cout << -1 << '\n';
			return 0;
		}
		if (row[0].size() <= col[0].size())
			rfunc();
		else
			cfunc();
		ans++;
	}
}