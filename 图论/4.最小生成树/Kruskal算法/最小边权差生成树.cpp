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
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
		scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].v);
	sort(a + 1, a + m + 1, cmp);
	int ans = 1 << 30;
	for (int i = 1; i <= m; i++) {
		int cnt = n;
		for (int j = 1; j <= m; j++)
			fa[j] = j;
		for (int j = i; j <= m; j++) {
			int x = findset(a[j].x), y = findset(a[j].y);
			if (x != y) {
				fa[x] = y;
				--cnt;
			}
			if (cnt == 1) {
				ans = min(ans, a[j].v - a[i].v);
				break;
			}
		}
	}
	printf("%d\n", ans);
}