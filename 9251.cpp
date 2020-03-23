#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

int m[1001][1001];
string s1, s2;

int lcs(int idx1, int idx2)
{
	if (idx1 == s1.size() || idx2 == s2.size())
		return 0;
	int &result = m[idx1][idx2];
	//m�迭�� �������� ��� s1�� ���� s2�� ���η� �ؼ�
	//������ ���̿��� �κм����� ������ ���̸� ã������
	if (result != -1)
		return result;
	return result = max(lcs(idx1 + 1, idx2), max(lcs(idx1, idx2 + 1), lcs(idx1 + 1, idx2 + 1) + (s1[idx1] == s2[idx2])));
	//idx+1,idx2->���δٸ� ���϶� ��������
	//idx, idx2 + 1->���δٸ� ���϶� ��������
	//idx1+1, idx2+1 -> ���� ������ 1���� (s1[idx1]==s2[idx2])
}

int main()
{
	cin >> s1 >> s2;
	memset(m, -1, sizeof(m));
	cout << lcs(0, 0) << '\n';
}