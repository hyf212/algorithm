#include <bits/stdc++.h>

using namespace std;

const int N = 100000;
int n, q, a[N + 1], dist[N + 1], f[N + 1][21], v[N + 1][21];
vector<int> edge[N + 1];

inline void dfs(int x) {
	for (auto y : edge[x])
		if (!dist[y]) {
			f[y][0] = x;
			dist[y] = dist[x] + 1;
			dfs(y);
		}
}
int main() {
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	memset(dist, 0, sizeof(dist));
	dist[1] = 1;
	dfs(1);
	memset(v, 127, sizeof(v));
	for (int i = 1; i <= n; i++)
		v[i][0] = a[i];
	for (int i = 1; i <= 20; i++)
		for (int j = 1; j <= n; j++)
			f[j][i] = f[f[j][i - 1]][i - 1],
			v[j][i] = min(v[j][i - 1], v[f[j][i - 1]][i - 1]);
	
	while (q--) {
		int x, y;
		scanf("%d%d", &x, &y);
		if (dist[x] < dist[y])
			swap(x, y);
		int z = dist[x] - dist[y];
		int ans = 1 << 30;
		for (int i = 0; z; z /= 2, i++)
			if (z & 1) {
				ans = min(ans, v[x][i]);
				x = f[x][i];
			}
		if (x != y) {
			for (int i = 20; i >= 0; i--)
				if (f[x][i] != f[y][i]) {
					ans = min(ans, v[y][i]);
					ans = min(ans, v[x][i]);
					x = f[x][i];
					y = f[y][i];
				}
			ans = min(ans, v[x][0]);
			ans = min(ans, v[y][0]);
			x = f[x][0];
		}
		ans = min(ans, v[x][0]);
		printf("%d\n", ans);
	}
}