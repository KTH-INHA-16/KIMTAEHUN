#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a[1001];
bool b[1001];

int main()
{
	int n, l;
	cin >> n >> l;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a+n);
	//정렬을 통해 앞에 있는 파이프부터
	//차례대로 테이프를 붙이면 최소한으로 테이핑할수 있기
	//때문
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (!b[a[i]])
			//bool 배열을 통해 해당 지점을 테이핑했는지 확인
		{
			for (int j = a[i]; j < min(a[i] + l, 1001); j++)
				//greedy 기법으로 차례대로 테이핑 겹쳐도 되므로
				b[j] = true;
			ans += 1;
		}
	}
	cout << ans << '\n';
}