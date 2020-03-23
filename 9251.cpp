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
	//m배열이 이차원인 경우 s1이 가로 s2를 세로로 해서
	//각각의 길이에서 부분수열의 공통의 길이를 찾기위함
	if (result != -1)
		return result;
	return result = max(lcs(idx1 + 1, idx2), max(lcs(idx1, idx2 + 1), lcs(idx1 + 1, idx2 + 1) + (s1[idx1] == s2[idx2])));
	//idx+1,idx2->서로다른 값일때 좌측증가
	//idx, idx2 + 1->서로다른 값일때 우측증가
	//idx1+1, idx2+1 -> 만약 같을때 1증가 (s1[idx1]==s2[idx2])
}

int main()
{
	cin >> s1 >> s2;
	memset(m, -1, sizeof(m));
	cout << lcs(0, 0) << '\n';
}