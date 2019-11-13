#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
	int n, k;
	cin >> n >> k;
	queue<int> q;
	int i = 1;
	while (i <= n)
	{
		q.push(i);
		i++;
	}
	printf("<");
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < k - 1; j++)
		{
			q.push(q.front());
			q.pop();
		}
		printf("%d, ", q.front());
		q.pop();
	}
	printf("%d>\n", q.front());
	return 0;
}