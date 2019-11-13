#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(void)
{
	int n, m, k;
	cin >> n >> m >> k;

	vector <int> v(n);

	
	if (m + k - 1 <= n && n <= m * k)
	{
		for (int i = 0; i < n; i++)
			v[i] = i + 1;
		vector<int>g;
		g.push_back(0);
		g.push_back(k);
		n -= k;
		m -= 1;
		int gs = m == 0 ? 1 : n / m;
		int r = m == 0 ? 0 : n % m;
		for (int i = 0; i < m; i++)
		{
			g.push_back(g.back() + gs + (r > 0 ? 1 : 0));
			if (r > 0)
				r--;
		}
		for (int i = 0; i < g.size() - 1; i++)
			reverse(v.begin() + g[i], v.begin() + g[i + 1]);
		for (int i = 0; i < v.size(); i++)
			cout << v[i] << ' ';
		cout << '\n';
	}
	else
		cout << -1 << endl;
}

/*
int N, M, K;
int main(void)
{
        ios_base::sync_with_stdio(0);
        cin.tie(0); //cin 속도 향
        cin >> N >> M >> K;

        //최대 부분 증가 수열과 최대 부분 감소 수열은 하나의 원소만 공유
        //N = M * K + 1인 경우: 길이가 M + 1인 증가 수열과 길이가 K + 1인 감소수열을 만들 수 있음
        if (M + K - 1 <= N && N <= M * K)
        {
                 vector<int> arr(N);
                 for (int i = 0; i < N; i++)
                         arr[i] = i + 1;
                 //하나의 그룹의 시작 인덱스
                 int idx = 0;
                 //M개의 그룹으로 나눈다
                 for (int i = 1; i <= M; i++)

                 {

                         //각 그룹에 들어있는 수는 K보다 작거나 같아야 하고

                         //주어진 조건을 만족시키기 위해서 한 그룹은 K개의 수를 같고 있다

                         int temp = min(idx + K, N - M + i);

                         //각 그룹을 뒤집어준다

                         reverse(arr.begin() + idx, arr.begin() + temp);

                         idx = temp;

                 }
                 for (int i = 0; i < N; i++)

                         cout << arr[i] << " ";

                 cout << "\n";

        }

        else

                 cout << -1 << "\n";

        return 0;

}

*/