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
        cin.tie(0); //cin �ӵ� ��
        cin >> N >> M >> K;

        //�ִ� �κ� ���� ������ �ִ� �κ� ���� ������ �ϳ��� ���Ҹ� ����
        //N = M * K + 1�� ���: ���̰� M + 1�� ���� ������ ���̰� K + 1�� ���Ҽ����� ���� �� ����
        if (M + K - 1 <= N && N <= M * K)
        {
                 vector<int> arr(N);
                 for (int i = 0; i < N; i++)
                         arr[i] = i + 1;
                 //�ϳ��� �׷��� ���� �ε���
                 int idx = 0;
                 //M���� �׷����� ������
                 for (int i = 1; i <= M; i++)

                 {

                         //�� �׷쿡 ����ִ� ���� K���� �۰ų� ���ƾ� �ϰ�

                         //�־��� ������ ������Ű�� ���ؼ� �� �׷��� K���� ���� ���� �ִ�

                         int temp = min(idx + K, N - M + i);

                         //�� �׷��� �������ش�

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