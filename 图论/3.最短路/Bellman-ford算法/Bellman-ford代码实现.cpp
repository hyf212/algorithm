时间复杂度为O(nm)
struct Edge {
	int x, y, v;
} edge[M + 1];
int n, m, dist[N + 1], pre[N + 1];

int shortestpath (int s, int t) {
	memset(dist, 127, sizeof(dist));
	dist[s] = 0;
	while (true) {
		bool ok = false;
		for (int i = 1; i <= m; i++) {
			int x = edge[i].x, y = edge[i].y, v = edge[i].v;
			if (dist[x] < 1 << 30)
				if (dist[x] + v < dist[y]) {
					dist[y] = dist[x] + v;
					pre[y] = x;
					ok = true;
				}
		}
		if (!ok)
			break;
	}
	return dist[t];
}