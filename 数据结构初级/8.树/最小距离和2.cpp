#include<bits/stdc++.h>

using namespace std;

int n, s[100001], pre[100001], dist[100001];
vector<int> edges[100001];

inline void dfs(int x) {
	for (auto y : edges[x])
		if (y != pre[x]) {
			pre[y] = x;
			dist[y] = dist[x] + 1;
			dfs(y);
		}
}
inline void solve(int x) {
	s[x] = 1;
	for (auto y : edges[x])
		if (y != pre[x]) {
			pre[y] = x;
			solve(y);
			s[x] += s[y];
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
	memset(pre, 0, sizeof(pre));
	pre[1] = -1;
	solve(1);
	
	int idx = 0, v = 1 << 30;
	for (int i = 1; i <= n; i++){
		int f = 0;
		for (auto y : edges[i]) {
			if (y != pre[i])
				f = max(f, s[y]);
			else
				f = max(f, n - s[i]);
			}
		if (f < v) {
			v = f;
			idx = i;
		}
	}
	memset(dist, 0, sizeof(dist));
	memset(pre, 0, sizeof(pre));
	pre[idx] = -1;
	dfs(idx);
	long long ans = 0;
	for (int i = 1; i <= n; i++)
		ans += dist[i];
	printf("%lld\n", ans);
	return 0;
}