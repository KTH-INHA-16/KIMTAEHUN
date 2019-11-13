#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int max_differ = 500000*50;

int n;
int a[51];
int d[51][250001];

int go(int b, int differ)
{
	if (differ > 250000)
		return -max_differ;
	//차이가 최대보다 벌어지면 더 벌어지지 못하게 처리
	//결국 못만드는 상황으로 가게 만들기
	if (b == n)
	{
		if (differ == 0)
			return 0;
		else
			return -max_differ;
		//위 else의 경우는 max함수의 결정값을 좀더 편하게 잡아주기 위해서 씌인다
	}
	int &ans = d[b][differ];
	if (ans != -1)
		return ans;
	ans = go(b + 1, differ);
	//그냥 다음블록으로 지나 치는 경우
	ans = max(ans, go(b + 1, differ + a[b]));
	//낮은 블럭에 블럭을 쌓고 가는 경우
	if (a[b]>differ)
	{
		ans = max(ans, differ + go(b + 1, a[b] - differ));
		//기존탑이 더 큰경우
		//작은 - 큰 + 그 다음 블럭차이
	}
	else
	{
		ans = max(ans, a[b] + go(b + 1, differ - a[b]));
		//0이였던 탑이 더 커져버린 경우
		//큰 - 작은 + 그 다음의 블럭 차이
	}
	return ans;
}



int main(void)
{
	cin >> n;
	memset(d, -1, sizeof(d));
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int ans = go(0, 0);
	if (ans == 0)
		cout << -1 << '\n';
	else
		cout << ans << '\n';
}