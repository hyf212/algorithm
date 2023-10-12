时间复杂度为O(mlogm)
struct Node {
	int x, y, v;
	bool operator <(const Node &A) const {
		return v < A.v;
	}
} a[M + 1];

int n, m, fa[N + 1];

int findset(int i) {
	if (i == fa[i])
		return i;
	return fa[i] = findset(fa[i]);
}

int Kruskal() {
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	sort(a + 1, a + 1 + m);
	int ans = 0, cnt = n;//cnt是多少连通块
	for (int i = 1; i <= m; i++) {
		int x = findset(a[i].x), y = findset(a[i].y);
		if (x != y) {
			fa[x] = y;
			ans += a[i].v;
			--cnt;
		}
		if (cnt == 1)
			break;
	}
	if (cnt != 1)
		return -1;
	else
		return ans;
}