#include<iostream>
#include<algorithm>

using namespace std;

const int MAX = 16;
int N, ans;
int T[MAX];
int P[MAX];

void brute(int today, int sum) {
	if (today == N + 1) {
		ans = max(ans, sum);
		return;
	}
	if (today > N) return;

	brute(today + T[today], sum + P[today]);
	//경우 1 : 상담을 하는경우
	brute(today + 1, sum);
	//경우 2 : 상담을 안하고 넘어가는 경우
}
//top-down


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> T[i] >> P[i];
	}

	brute(1, 0);

	cout << ans << '\n';
	return 0;
}