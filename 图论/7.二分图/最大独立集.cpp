#include <bits/stdc++.h>

using namespace std;

vector<int> edge[1001];
int n, m, c[1001], a[10001][2], n1, n2, v[1001], r[1001];
bool b[1001];
bool find(int x) {
	b[x] = true;
	for (auto y : edge[x])
		if (!v[y] || (!b[v[y]] && find(v[y]))) {
			v[y] = x;
			return true;
		}
	return false;
}
int match() {
	int ans = 0;
	memset(v, 0, sizeof(v));
	for (int i = 1; i <= n1; i++) {
		memset(b, false, sizeof(b));
		if (find(i))
			++ans;
	}
	return ans;
}
inline void dfs(int x) {
	for (auto y : edge[x]) {
		if (!c[y]) {
			c[y] = 3 - c[x];
			dfs(y);
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &a[i][0], &a[i][1]);
		edge[a[i][0]].push_back(a[i][1]);
		edge[a[i][1]].push_back(a[i][0]);
	}
	memset(c, 0, sizeof(c));
	for (int i = 1; i <= n; i++)
		if (!c[i]) {
			c[i] = 1;
			dfs(i);
		}
	n1 = n2 = 0;
	for (int i = 1; i <= n; i++)
		if (c[i] == 1)
			r[i] = ++n1;
		else
			r[i] = ++n2;
	for (int i = 1; i <= n; i++)
		edge[i].clear();
	for (int i = 1; i <= m; i++) {
		int x = a[i][0], y = a[i][1];
		if (c[x] == 1)
			edge[r[x]].push_back(r[y]);
		else
			edge[r[y]].push_back(r[x]);	
	}
	printf("%d\n", n - match());
}