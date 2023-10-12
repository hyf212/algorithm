#include<bits/stdc++.h>

using namespace std;

int n, cnt, pre[1001], dist[1001], f[1001];
vector<int> edges[1001];

inline void dfs(int x) {
	for (auto y : edges[x])
		if (y != pre[x]) {
			pre[y] = x;
			dist[y] = dist[x] + 1;
			dfs(y);
		}
}
inline void solve(int x) {
	++cnt;
	for (auto y : edges[x])
		if (y != pre[x]) {
			pre[y] = x;
			solve(y);
		}
}
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		edges[x].push_back(y);
		edges[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) {
		f[i] = 0;
		memset(pre, 0, sizeof(pre));
		for (auto y : edges[i]) {
			cnt = 0;
			pre[y] = i;
			solve(y);
			f[i] = max(f[i], cnt);
		}
	}
	int idx = 0, v = 1 << 30;
	for (int i = 1; i <= n; i++)
		if (v > f[i]) {
			v = f[i];
			idx = i;
		}
	memset(dist, 0, sizeof(dist));
	memset(pre, 0, sizeof(pre));
	pre[idx] = -1;
	dfs(idx);
	int ans = 0;
	v = 0;
	for (int i = 1; i <= n; i++)
		ans += dist[i];
	printf("%d\n", ans);
	return 0;
}