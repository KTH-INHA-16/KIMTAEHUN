#include <iostream>
#include <string>
using namespace std;
//백트레킹 -> dfs를 실행 하면서 유망하지않은 
//경우의수는 제외를 하고 다음 경우로 넘어가는 경우

int n;
string ans;

void dfs(char c, int cnt)
{
	if (cnt - 1 == n)
	{
		cout << ans << '\n';
		//조건을 만족 하는 경우
		//제일 먼저 나오는수가 작은수일 경우
		exit(0);
		//exit(0) -> 함수자체의 강제 종료
		//return -> 그 단계의 함수 종료
	}
	ans += c;
	//숫자 삽입
	for (int i = 1; i <= cnt / 2; i++)
		//수열 검사 부분
		//1/2지점까지만 검사
	{
		string a = ans.substr(cnt - i, i);
		//1/2이상 지점의 수열
		string b = ans.substr(cnt - i * 2, i);
		//1/2이하 지점의 수열
		if (a == b)
			//수열이 같은 경우
		{
			ans.erase(cnt - 1);
			//해당 수열 삭제
			return;
		}
	}
	for (int i = 1; i <= 3; i++)
		dfs(i + '0', cnt + 1);
	//문자열 추가 -> dfs(실행)
	ans.erase(cnt - 1);
	//cnt - 1자리 성립하지 않는 경우
}

int main()
{
	cin >> n;
	for (int i = 1; i <= 3; i++)
		dfs(i + '0', 1);
	//모든 경우에 해당해서 실행
	return 0;
}