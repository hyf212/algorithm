struct Node {
	int y, idx;
	Node(int _y, int _idx) {y = _y, idx = _idx;}
};
vector<Node> edge[N + 1];
int n, m, l, cnt = 1, f[N + 1], v[N + 1], d[N + 1], c[M + 2];
bool b[2 * M + 2];

inline void dfs(int x) {
	while (f[x] < v[x]) {
		int y = edge[x][f[x]].y, idx = edge[x][f[x]].idx;
		if (!b[idx]) {
			f[x]++;
			b[idx] = b[idx ^ 1] = true;
			dfs(y);
			c[++l] = y;
		} else
			f[x]++;
	}
}

inline void Euler() {
	int x = 0, y = 0;
	for (int i = 1; i <= n; i++)
		if (d[i] & 1)
			x = i, ++y;
	if (y && y != 2) {
		printf("No\n");
		return ;
	}
	if (!x)
		for (int i = 1; i <= n; i++)
			if (d[i])
				x = i;
	memset(f, 0, sizeof(f));
	memset(b, false, sizeof(b));
	l = 0;
	dfs(x);
	c[++l] = x;
	if (l != m + 1) {
		printf("No\n");
		return ;
	}
	printf("Yes\n");
	for (int i = l; i; --i)
		printf("%d ", c[i]);
}