#include <iostream>
#include <algorithm>
using namespace std;

int heap[100001];
int hn;

int pop()
{
	int ans = heap[1];
	heap[1] = heap[hn];
	heap[hn--] = 0;
	for (int i = 1; 2 * i <= hn;)
	{
		if (heap[i] > heap[i * 2] && heap[i] > heap[i * 2 + 1])
			break;
		else if (heap[i * 2] < heap[i * 2 + 1])
		{
			swap(heap[i], heap[i * 2]);
			i = i * 2;
		}
		else
		{
			swap(heap[i], heap[i * 2 + 1]);
			i = i * 2 + 1;
		}
	}
	return ans;
}

void push(int x)
{
	heap[++hn] = x;
	for (int i = hn; i > 1; i /= 2)
	{
		if (heap[i / 2] > heap[i])
		{
			swap(heap[i / 2], heap[i]);
		}
		else
			break;
	}
}

int main(void)
{
	int n;
	cin >> n;
	while (n--)
	{
		int t;
		cin >> t;
		if (t != 0)
		{
			push(t);
		}
		else
		{
			if (hn == 0)
				printf("0\n");
			else
				printf("%d\n", pop());
				
		}
	}
}