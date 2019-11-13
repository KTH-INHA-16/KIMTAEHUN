#include <iostream>
#include <stack>
using namespace std;

long long arr[100001];

int main(void)
{
	while (true)
	{
		int n;
		cin >> n;
		if (n == 0)
			break;
		else
		{
			for (int i = 0; i < n; i++)
			{
				cin >> arr[i];
			}
			stack<long long> s;
			long long ans = 0;
			for (int i = 0; i < n; i++)
			{
				int left = i;
				while (!s.empty() && arr[s.top()] > arr[i])
				{
					long long height = arr[s.top()];
					s.pop();
					long long width = i;
					if (!s.empty())
						width = (i - s.top() - 1);
					if (ans < width*height)
						ans = width * height;
				}
				s.push(i);
			}
			while (!s.empty()) 
			{
				long long height = arr[s.top()];
				s.pop();
				long long width = n;
				if (!s.empty())
				{
					width = n - s.top() - 1;
				}
				if (ans < width*height)
				{
					ans = width * height;
				}
			}
			cout << ans << '\n';
		}
	}
}