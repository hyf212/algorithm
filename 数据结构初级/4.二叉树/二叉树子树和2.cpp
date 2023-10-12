#include<bits/stdc++.h>

using namespace std;

int n, v[1000001];
struct TreeNode {
	int value;
	int l, r, fa;
} a[1000001];
int solve(int t) {
	int x = a[t].value;
	if (a[t].l)
		x += solve(a[t].l);
	if (a[t].r)
		x += solve(a[t].r);
	v[t] = x;
	return x;
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
	solve(1);
	for (int i = 1; i <= n; i++)
		printf("%d ", v[i]);
	return 0;
}