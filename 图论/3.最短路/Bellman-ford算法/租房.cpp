#include <bits/stdc++.h>

using namespace std;

const int N = 5000;
const int M = 20000;
struct Edge {
	int x, y, v;
} edge[M + 1];
int n, m, a, b, c, cnt, dist[N + 1], f[3][N + 1]; 

inline void shortestpath(int s) {
	memset(dist, 127, sizeof(dist));
	dist[s] = 0;
	while (true) {
		bool ok = false;
		for (int i = 1; i <= 2 * m; i++) {
			int x = edge[i].x, y = edge[i].y, v = edge[i].v;
			if (dist[x] < 1 << 30)
				if (dist[x] + v < dist[y]) {
					dist[y] = dist[x] + v;
					ok = true;
				}
		}
		if (!ok)
			break;
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int x, y, v;
		scanf("%d%d%d", &x, &y, &v);
		edge[++cnt].x = x, edge[cnt].y = y, edge[cnt].v = v;
		edge[++cnt].x = y, edge[cnt].y = x, edge[cnt].v = v;
	}
	scanf("%d%d%d", &a, &b, &c);
	shortestpath(a);
	memcpy(f[0], dist, sizeof(dist));
	shortestpath(b);
	memcpy(f[1], dist, sizeof(dist));
	shortestpath(c);
	memcpy(f[2], dist, sizeof(dist));
	int ans = 1 << 30;
	for (int i = 1; i <= n; i++)
		ans = min(ans, f[0][i] + f[1][i] + f[2][i]);
	printf("%d\n", ans);
}