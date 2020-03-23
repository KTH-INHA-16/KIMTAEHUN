#include <iostream>
using namespace std;

//1부터 분해합을 만든다
// 분해합이 입력값 같을 경우 분해합 x
// 아닌경우는 모든경우 존재
int n;

int find()
{
	int cnt = 1;
	while (1)
	{
		int copy = cnt;
		int sum = cnt;
		while (copy)
		{
			sum += copy % 10;
			copy /= 10;
		}
		if (cnt == n || sum == n)
			break;
		cnt++;
		//브루트 포스의 기본
	}
	return cnt;
}

int main()
{

	cin >> n;
	int ans = find();
	if (ans == n)
		cout << 0 << '\n';
	else
		cout << ans << '\n';
}