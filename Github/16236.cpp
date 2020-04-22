#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <functional>
using namespace std;

const int MAX = 20;

/*
1. 현재 아기 상어의 위치를 start 변수에 저장하고 해당 위치를 0으로 초기화해줍니다.

2. 큐에 위치를 넣어주고 시뮬레이션을 시작합니다.

3. 시뮬레이션을 위해 두 개의 우선순위 큐가 필요한데 하나는 아기 상어가 지나가는 경로를 위해 다른 하나는 먹이의 후보를 위해 필요합니다.

4. 경로는 시간, y, x 순서로 작을수록 높은 우선순위가 부여되고 먹이는 y, x 순서로 작을수록 높은 우선순위가 부여됩니다.

5. 핵심은 같은 거리 내에 있는 모든 후보를 비교하기 위해 경로 우선순위 큐의 크기만큼 반복문을 돌려 먹이 후보를 파악하는 것이였습니다.

6. 먹이 후보가 나타난다면 아기 상어는 더 멀리 움직일 필요가 없으므로 반복문을 탈출하고 더 이상 먹이를 찾을 수 없을 때까지 2 ~ 5 과정을 반복합니다.
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
// pq에 사용하는 operator
//시간 같으면 y가 높은 순
//시간 과 y가 같으면 x가 높은 순
//즉 좌측 상단을 먼저 생각
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
			//상어의 위치
			if (arr[i][j] == 9)
			{
				start = { i, j };
				//0으로 초기화
				arr[i][j] = 0;
			}
		}

	queue<pair<pair<int, int>, int>> q;
	//초기 시작 qeueue
	q.push({ { start }, 2 });
	//결과
	int duration = 0;
	//먹은 생선 마리수
	int cnt = 0;

	while (!q.empty())
	{
		int y = q.front().first.first;
		int x = q.front().first.second;
		int size = q.front().second;
		q.pop();

		//매번 visited 초기화 해줘야 함!
		memset(visited, false, sizeof(visited));
		//가는 경로 우선순위 위해 
		//최대한 좌측상단으로 배정(시간이 같을때)
		priority_queue<pass> temp;
		temp.push({ 0, y, x });
		visited[y][x] = true;

		while (!temp.empty())
		{
			//같은 거리 내 모두 비교
			int iter = temp.size();
			//우선순위는 y가 작은순, y가 같다면 x가 작은순입니다.
			// 좌측 상단
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

					//범위 내에 있고
					if (0 <= nextY && nextY < N && 0 <= nextX && nextX < N)
						//방문하지 않았으며
						if (!visited[nextY][nextX])
						{
							//지나갈 수 있다면
							if (arr[nextY][nextX] <= size)
							{
								temp.push({ curTime + 1, nextY, nextX });
								visited[nextY][nextX] = true;
								//먹이 후보 중 하나
								if (1 <= arr[nextY][nextX] && arr[nextY][nextX] < size)
									pq.push({ { nextY, nextX }, curTime + 1 });
							}
						}
				}
			}

			//우선순위가 제일 높은 먹이를 먹는다
			if (!pq.empty())
			{
				cnt++;
				// 크기 커질 조건
				if (cnt == size)
				{
					q.push({ { pq.top().first }, size + 1 });
					cnt = 0;
				}
				else
					q.push({ {pq.top().first}, size });
				//초기화 해주고
				arr[pq.top().first.first][pq.top().first.second] = 0;
				//시간을 더해준다
				duration += pq.top().second;
				break;
			}
		}
	}

	cout << duration << "\n";
	return 0;
}