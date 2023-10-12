#include <bits/stdc++.h>

using namespace std;

struct Edge {
	int x, y, v;
} edge[4001];

int n, m, k, cnt, f[501][11];

inline void shortestpath(int s, int t) {
	memset(f, 127, sizeof(f));
	f[s][0] = 0;
	for (int i = 1; i <= n; i++) {
		bool ok = false;
		for (int j = 1; j <= cnt; j++) {
			int x = edge[j].x, y = edge[j].y, v = edge[j].v;
			for (int l = 0; l <= k; l++)
				if (f[x][l] < 1 << 30) {
					if (f[x][l] + v < f[y][l]) {
						f[y][l] = f[x][l] + v;
						ok = true;
					}
					if (l != k && f[x][l] + v / 2 < f[y][l + 1]) {
						f[y][l + 1] = f[x][l] + v / 2;
						ok = true;
					}
				}
		}
		if (!ok)
			break;
	}
	int ans = 1 << 30;
	for (int i = 0; i <= k; i++)
		ans = min(ans, f[n][i]);
	printf("%d", ans);
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		int x, y, v;
		scanf("%d%d%d", &x, &y, &v);
		edge[++cnt].x = x, edge[cnt].y = y, edge[cnt].v = v;
		edge[++cnt].x = y, edge[cnt].y = x, edge[cnt].v = v;
	}
	shortestpath(1, n);
}