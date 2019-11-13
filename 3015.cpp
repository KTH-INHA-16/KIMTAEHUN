#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

long long a[500001];
long long ans;

int main()
{
	int n;
	cin >> n;
	for (int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	stack <pair<int,int>> s;
	for (int i = 0; i < n; i++)
	{
		pair<int, int> p = { a[i],1 };
		//키가 같은 경우를 pair로 추가
		while (!s.empty())
		{
			if (s.top().first <= a[i])
			{
				ans += (long long)s.top().second;
				//키가 같은 사람 추가
				if (s.top().first == a[i])
					//만약 같으면
					//뒤의 인덱스 추가
				{
					p.second += s.top().second;
				}
				s.pop();
			}
			else
			{
				break;
			}
		}
		if (!s.empty())
			//비어있지 않으면 1추가
			//스택의 가장 위에있는 사람은 a보다 키가 큰데 그 사람은 볼 수 있기 때문
			ans += 1LL;
		s.push(p);
			//다시 push
	}
	cout << ans << '\n';
}