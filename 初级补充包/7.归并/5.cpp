#include <bits/stdc++.h>

using namespace std;

struct Node {
	long long v;
	int ans;
} a[100001], c[100001];
bool cmp(Node x, Node y) {
	return x.v < y.v;
}
bool bmp(Node x, Node y) {
	return x.ans < y.ans;
}
int n, m;
long long b[100001];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i].v);
		a[i].ans = i;
	}
	for (int i = 1; i <= m; i++)
		scanf("%lld", &b[i]);
	sort(a + 1, a + n + 1, cmp);
	sort(b + 1, b + m + 1);
	int i = 1, j = 1, cnt = 0;
	while (i <= n && j <= m) {
		while (j <= m && a[i].v > b[j])
			j++;
		while (i <= n && a[i].v < b[j])
			i++;
		if (a[i].v == b[j] && i <= n && j <= m) {
			c[++cnt].v = a[i].v;
			c[cnt].ans = a[i].ans;
			i++, j++;
		}
	}
	
	sort(c + 1, c + cnt + 1, cmp);
	for (int i = 1; i <= cnt; i++)
		printf("%lld ", c[i].v);
}