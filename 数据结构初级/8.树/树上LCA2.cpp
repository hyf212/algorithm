#include<bits/stdc++.h>

using namespace std;

int n, m, dist[100001], fa[100001][21];
vector<int> edges[100001];
inline void dfs(int x) {
	for (auto y : edges[x]) {
		dist[y] = dist[x] + 1;
		dfs(y);
	}
}
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		edges[x].push_back(y);
		fa[y][0] = x;
	}
	for (int i = 1; i <= 20; i++)
		for (int j = 1; j <= n; j++)
			if (fa[j][i - 1])
				fa[j][i] = fa[fa[j][i - 1]][i - 1];
	memset(dist, 0, sizeof(dist));
	dfs(1);
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		if (dist[x] < dist[y])
			swap(x, y);
		int l = dist[x] - dist[y];
		for (int j = 0; j <= 20 && l; j++, l /= 2)
			if (l & 1)
				x = fa[x][j];
		if (x == y) {
			printf("%d\n", x);
			continue;
		}
		for (int j = 20; j >= 0; j--)
			if (fa[x][j] != fa[y][j])
				x = fa[x][j], y = fa[y][j];
		printf("%d\n", fa[x][0]);
	}
	 return 0;
}