#include<bits/stdc++.h>

using namespace std;

int n, m, dist[1001], fa[1001];
vector<int> edges[1001];
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
		fa[y] = x; 
	}
	memset(dist, 0, sizeof(dist));
	dfs(1);
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		if (dist[x] < dist[y])
			swap(x, y);
		int l = dist[x] - dist[y];
		for (int i = 1; i <= l; i++)
			x = fa[x];
		int len = dist[x];
		while (x != y)
			x = fa[x], y = fa[y];
		printf("%d\n", x);
	}
	 return 0;
}