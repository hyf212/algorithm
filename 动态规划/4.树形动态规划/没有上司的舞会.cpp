/*#include <bits/stdc++.h>

using namespace std;

struct Node {
	int where;
	Node *next;
} *first[100001], a[100001];
int n, v[100001], l;
long long f[100001][2];
inline void makelist(int x, int y) {
	a[++l].where = y;
	a[l].next = first[x];
	first[x] = &a[l];
}
inline void solve (int i) {
	f[i][1] = v[i];
	for (Node *p = first[i]; p; p = p->next) {
		solve(p->where);
		f[i][0] += max(f[p->where][1], f[p->where][0]);
		f[i][1] += f[p->where][0];
	}
}
int main(void) {
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		int x;
		scanf("%d", &x);
		makelist(x, i);
	}
	for (int i = 1; i <= n; i++)
		scanf("%d", &v[i]);
	solve(1);
	printf("%lld\n", max(f[1][1], f[1][0]));
	return 0;
}*/