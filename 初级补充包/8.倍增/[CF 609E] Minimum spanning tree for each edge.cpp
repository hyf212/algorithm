#include <bits/stdc++.h>

using namespace std;

const int N = 200000;
struct Node {
	int x, y, v, idx;
	bool operator < (const Node &A) const {
		return v < A.v;
	}
} a[N + 1];

struct Edge {
	int y, v;
	Edge(int _y, int _v)  {y = _y;  v = _v;}
};

vector<Edge> edge[N + 1];
int n, m, fa[N + 1], dist[N + 1], f[N + 1][21], v[N + 1][21];

long long q[N + 1];

int getfind(int i) {
	if (i == fa[i])
		return i;
	return fa[i] = getfind(fa[i]);
}

inline void dfs(int x) {
	for (auto i : edge[x])
		if (!dist[i.y]) {
			dist[i.y] = dist[x] + 1;
			f[i.y][0] = x;
			v[i.y][0] = i.v;
			dfs(i.y);
		}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].v);
		a[i].idx = i;
	}
	sort(a + 1, a + m + 1);
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	long long res = 0;
	for (int i = 1; i <= m; i++) {
		int x = getfind(a[i].x), y = getfind(a[i].y);
		if (x != y) {
			res += a[i].v;
			edge[a[i].x].push_back(Edge(a[i].y, a[i].v));
			edge[a[i].y].push_back(Edge(a[i].x, a[i].v));
			fa[x] = y;	
		}
	}
	memset(dist, 0, sizeof(dist));
	dist[1] = 1;
	dfs(1);
	for (int i = 1; i <= 20; i++)
		for (int j = 1; j <= n; j++)
			f[j][i] = f[f[j][i - 1]][i - 1],
			v[j][i] = max(v[j][i - 1], v[f[j][i - 1]][i - 1]);
	for (int i = 1; i <= m; i++) {
		int x = a[i].x, y = a[i].y;
		if (dist[x] < dist[y])
			swap(x, y);
		int z = dist[x] - dist[y];
		int ans = 0;
		for (int j = 0; z; z /= 2, j++)
			if (z & 1) {
				ans = max(ans, v[x][j]);
				x = f[x][j];
			}
		if (x != y) {
			for (int j = 20; j >= 0; j--)
				if (f[x][j] != f[y][j]) {
					ans = max(ans, v[x][j]);
					ans = max(ans, v[y][j]);
					x = f[x][j];
					y = f[y][j];
				}
			ans = max(ans, v[x][0]);
			ans = max(ans, v[y][0]);
		}
		q[a[i].idx] = res - ans + a[i].v;
	}
	for (int i = 1; i <= m; i++)
		printf("%lld\n", q[i]);
}