#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <functional>
using namespace std;

const int MAX = 20;

/*
1. ���� �Ʊ� ����� ��ġ�� start ������ �����ϰ� �ش� ��ġ�� 0���� �ʱ�ȭ���ݴϴ�.

2. ť�� ��ġ�� �־��ְ� �ùķ��̼��� �����մϴ�.

3. �ùķ��̼��� ���� �� ���� �켱���� ť�� �ʿ��ѵ� �ϳ��� �Ʊ� �� �������� ��θ� ���� �ٸ� �ϳ��� ������ �ĺ��� ���� �ʿ��մϴ�.

4. ��δ� �ð�, y, x ������ �������� ���� �켱������ �ο��ǰ� ���̴� y, x ������ �������� ���� �켱������ �ο��˴ϴ�.

5. �ٽ��� ���� �Ÿ� ���� �ִ� ��� �ĺ��� ���ϱ� ���� ��� �켱���� ť�� ũ�⸸ŭ �ݺ����� ���� ���� �ĺ��� �ľ��ϴ� ���̿����ϴ�.

6. ���� �ĺ��� ��Ÿ���ٸ� �Ʊ� ���� �� �ָ� ������ �ʿ䰡 �����Ƿ� �ݺ����� Ż���ϰ� �� �̻� ���̸� ã�� �� ���� ������ 2 ~ 5 ������ �ݺ��մϴ�.
*/

typedef struct
{
	int y, x;
}Dir;

Dir moveDir[4] = { {-1, 0}, {0, -1}, {0, 1}, {1, 0 } };

typedef struct
{
	int time, y, x;
}pass;

bool operator<(const pass& p1, const pass& p2)
// pq�� ����ϴ� operator
//�ð� ������ y�� ���� ��
//�ð� �� y�� ������ x�� ���� ��
//�� ���� ����� ���� ����
{
	if (p1.time > p2.time)
		return true;
	else if (p1.time == p2.time && p1.y > p2.y)
		return true;
	else if (p1.time == p2.time && p1.y == p2.y && p1.x > p2.x)
		return true;
	return false;
}

int arr[MAX][MAX];
bool visited[MAX][MAX];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;

	pair<int, int> start;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
			//����� ��ġ
			if (arr[i][j] == 9)
			{
				start = { i, j };
				//0���� �ʱ�ȭ
				arr[i][j] = 0;
			}
		}

	queue<pair<pair<int, int>, int>> q;
	//�ʱ� ���� qeueue
	q.push({ { start }, 2 });
	//���
	int duration = 0;
	//���� ���� ������
	int cnt = 0;

	while (!q.empty())
	{
		int y = q.front().first.first;
		int x = q.front().first.second;
		int size = q.front().second;
		q.pop();

		//�Ź� visited �ʱ�ȭ ����� ��!
		memset(visited, false, sizeof(visited));
		//���� ��� �켱���� ���� 
		//�ִ��� ����������� ����(�ð��� ������)
		priority_queue<pass> temp;
		temp.push({ 0, y, x });
		visited[y][x] = true;

		while (!temp.empty())
		{
			//���� �Ÿ� �� ��� ��
			int iter = temp.size();
			//�켱������ y�� ������, y�� ���ٸ� x�� �������Դϴ�.
			// ���� ���
			priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, greater<pair<pair<int, int>, int>>> pq;
			for (int j = 0; j < iter; j++)
			{
				int curY = temp.top().y;
				int curX = temp.top().x;
				int curTime = temp.top().time;
				temp.pop();

				for (int i = 0; i < 4; i++)
				{
					int nextY = curY + moveDir[i].y;
					int nextX = curX + moveDir[i].x;

					//���� ���� �ְ�
					if (0 <= nextY && nextY < N && 0 <= nextX && nextX < N)
						//�湮���� �ʾ�����
						if (!visited[nextY][nextX])
						{
							//������ �� �ִٸ�
							if (arr[nextY][nextX] <= size)
							{
								temp.push({ curTime + 1, nextY, nextX });
								visited[nextY][nextX] = true;
								//���� �ĺ� �� �ϳ�
								if (1 <= arr[nextY][nextX] && arr[nextY][nextX] < size)
									pq.push({ { nextY, nextX }, curTime + 1 });
							}
						}
				}
			}

			//�켱������ ���� ���� ���̸� �Դ´�
			if (!pq.empty())
			{
				cnt++;
				// ũ�� Ŀ�� ����
				if (cnt == size)
				{
					q.push({ { pq.top().first }, size + 1 });
					cnt = 0;
				}
				else
					q.push({ {pq.top().first}, size });
				//�ʱ�ȭ ���ְ�
				arr[pq.top().first.first][pq.top().first.second] = 0;
				//�ð��� �����ش�
				duration += pq.top().second;
				break;
			}
		}
	}

	cout << duration << "\n";
	return 0;
}