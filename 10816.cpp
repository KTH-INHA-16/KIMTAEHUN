#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
	int n;
	scanf_s("%d", &n);

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &a[i]);
	}

	sort(a.begin(), a.end());

	int m;
	scanf_s("%d", &m);

	for (int i = 0; i < m; i++) {
		int number;
		scanf_s("%d", &number);
		auto p = equal_range(a.begin(), a.end(), number);
		printf("%d ", p.second - p.first);
	}

	printf("\n");
	return 0;
}