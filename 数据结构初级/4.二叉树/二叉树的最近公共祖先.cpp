/*#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
	int l, r, fa;
} a[1001];
int n;
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
	int u, v;
	scanf("%d%d", &u, &v);
	int len1 = 0, len2 = 0, c1[1001], c2[1001], c[1001];
	while (u != 1)
		c1[++len1] = u, u = a[u].fa;
	c1[++len1] = 1;
	while (v != 1)
		c2[++len2] = v, v = a[v].fa;
	c2[++len2] = 1;
	int len = 0;
	while (len1 && len2){
		if (c1[len1] == c2[len2])
			c[++len] = c1[len1], len1--, len2--;
		if (c1[len1] != c2[len2])
			break;
	}
	printf("%d", c[len]);
	return 0;
}*/
#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
	int l, r, fa;
	int depth;
} a[1001];
int n;
int main(void) {
	scanf("%d", &n);
	a[1].depth = 1;
	for (int i = 1; i <= n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		if (x)
			a[i].l = x, a[x].fa = i, a[x].depth = a[i].depth + 1;
		if (y)
			a[i].r = y, a[y].fa = i, a[y].depth = a[i].depth + 1;
	}
	int u, v;
	scanf("%d%d", &u, &v);
	if (a[u].depth < a[v].depth)
		swap(u, v);
	int x = a[u].depth - a[v].depth;
	for (int i = 1; i <= x; i++)
		u = a[u].fa;
	while (u != v)
		u = a[u].fa, v = a[v].fa;
	printf("%d", u);
	return 0;
}