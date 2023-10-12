vector<int> edge[N + 1];
int n, m, c[N + 1];

bool dfs(int x) {
	for (auto y : edge[x])
		if (!c[y]) {
			c[y] = 3 - c[x];
			if (!dfs(y))
				return false;
		} else
			if (c[x] == c[y])
				return false;
	return true;
}

bool check() {
	memset(c, 0, sizeof(c));
	for (int i = 1; i <= n; i++)
		if (!c[i]) {
			c[i] = 1;
			if (!dfs(i))
				return false;
		}
	return true;
}