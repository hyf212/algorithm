#include<bits/stdc++.h>

using namespace std;

int n, cnt;
struct TreeNode {
	int value;
	int l, r, fa;
} a[1001];
inline void solve(int t) {
	cnt += a[t].value;
	if (a[t].l)
		solve(a[t].l);
	if (a[t].r)
		solve(a[t].r);
}
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		if (x)
			a[i].l = x, a[x].fa = i;
		if (y)
			a[i].r = y, a[y].fa = i;
	}
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i].value);
	for (int i = 1; i <= n; i++) {
		cnt = 0;
		solve(i);
		printf("%d ", cnt);
	}
}