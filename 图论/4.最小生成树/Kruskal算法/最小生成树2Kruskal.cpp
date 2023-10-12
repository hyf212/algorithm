#include <bits/stdc++.h>

using namespace std;

const int N = 50000;
const int M = 100000;

struct Node {
	int x, y, v;
} a[M + 1];

int n, m, fa[N + 1];

bool cmp(Node x, Node y) {
	return x.v < y.v;
}

int findset(int i) {
	if (i == fa[i])
		return i;
	return fa[i] = findset(fa[i]);
}

void Kruskal() {
	int ans = 0;
	for (int i = 1; i <= m; i++) {
		int x = findset(a[i].x), y = findset(a[i].y);
		if (x != y) {
			ans += a[i].v;
			fa[x] = y;
		}
	}
	printf("%d\n", ans);
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
		scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].v);
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	sort(a + 1, a + m + 1, cmp);
	Kruskal();
}