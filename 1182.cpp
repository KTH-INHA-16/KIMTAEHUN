#include <iostream>
using namespace std;

int a[20];//집합의 길이
int n, s;
int ans;//몇가지 집합이 가능한지 경우

void find(int idx, int sum)
{
	if (idx == n)//재귀함수 호출시 마지막 인덱스에 도달했을때
	{
		if (sum == s)//이때까지의 합이 s랑 같을경우
		{
			ans += 1;//부분집합 수 증가
		}
		return;//재귀함수 종료부분
	}
	//백트레킹
	// 값을 더해주고 idx를 1더함
	find(idx +1 , sum + a[idx]);
	//인덱스 하나증가 + 총합 추가
	//그냥 idx를 더해줌
	find(idx + 1, sum);
	//단순 인덱스 증가->백트레킹 핵심
}

int main(void)
{
	cin >> n >> s;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	find(0, 0);//0부터 넣음
	if (s == 0)//0인 경우가 카운트가 1이 더 증가하므로
		ans -= 1;//1을 빼줌
	cout << ans << endl;
}