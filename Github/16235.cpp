#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

const int MAX = 10;

typedef struct
{
	int y, x;
}Dir;

Dir moveDir[8] = { {1, 1}, {1, 0}, {1, -1}, {0, 1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1} };

int arr[MAX][MAX];
int nutrient[MAX][MAX];
vector<int> v[MAX][MAX];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N, M, K;
	cin >> N >> M >> K;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> nutrient[i][j];
			arr[i][j] = 5;
		}

	for (int i = 0; i < M; i++)
	{
		int y, x, age;
		cin >> y >> x >> age;

		v[y - 1][x - 1].push_back(age);
	}

	for (int k = 0; k < K; k++)
	{
		//봄, 여름
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < N; x++)
			{
				if (v[y][x].size())
				{
					int dead = 0;
					vector<int> temp;

					sort(v[y][x].begin(), v[y][x].end());
					for (int i = 0; i < v[y][x].size(); i++)
					{
						int age = v[y][x][i];
						if (arr[y][x] >= age)
						{
							arr[y][x] -= age;
							temp.push_back(age + 1);
							//다른 vector에 저장 후 다시 늘림
							//하나씩 제거 + 삽입 시간 너무 소요
						}
						else
							dead += age / 2;
					}

					v[y][x].clear();
					for (int i = 0; i < temp.size(); i++)
						v[y][x].push_back(temp[i]);

					arr[y][x] += dead;
				}
			}
		}
		//가을
		for (int y = 0; y < N; y++)
			for (int x = 0; x < N; x++)
			{
				if (v[y][x].size())
				{
					for (int i = 0; i < v[y][x].size(); i++)
					{
						int age = v[y][x][i];

						if (age % 5 == 0)
						{
							for (int d = 0; d < 8; d++)
							{
								int nextY = y + moveDir[d].y;
								int nextX = x + moveDir[d].x;

								if (0 <= nextY && nextY < N && 0 <= nextX && nextX < N)
									v[nextY][nextX].push_back(1);
							}
						}
					}
				}
			}
		//겨울
		for (int y = 0; y < N; y++)
			for (int x = 0; x < N; x++)
				arr[y][x] += nutrient[y][x];
	}

	int result = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			result += v[i][j].size();

	cout << result << "\n";
	return 0;
}