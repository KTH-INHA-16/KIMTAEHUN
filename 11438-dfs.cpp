#pragma warning(disable:4996)
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;
const int MAX = 100111;
vector<int> a[MAX];
int p[MAX][18];
//2^n만큼 이동
int tin[MAX];
int tout[MAX];
int timer;
int l;
void dfs(int v, int parent) {
	tin[v] = ++timer;
	p[v][0] = parent;
	for (int i = 1; i <= l; i++) {
		p[v][i] = p[p[v][i - 1]][i - 1];
	}
	for (int to : a[v]) {
		if (to != parent) {
			dfs(to, v);
		}
	}
	tout[v] = ++timer;
}
bool upper(int u, int v) {
	return (tin[u] <= tin[v] && tout[u] >= tout[v]);
	//in이 u가 v보다 작을때 나올때 u가 더 클때
}
int lca(int u, int v) {
	if (upper(u, v)) return u;
	if (upper(v, u)) return v;
	for (int i = l; i >= 0; i--) {
		if (!upper(p[u][i], v)) {
			u = p[u][i];
		}
	}
	return p[u][0];
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		a[u].push_back(v);
		a[v].push_back(u);
	}
	for (l = 1; (1 << l) <= n; l++);
	l -= 1;
	//2진수 만큼 늘리기
	dfs(1, 1);
	int m;
	scanf("%d", &m);
	while (m--) {
		int u, v;
		scanf("%d %d", &u, &v);
		printf("%d\n", lca(u, v));
	}
	return 0;
}