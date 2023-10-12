#include <bits/stdc++.h>

using namespace std;

struct node {
	node *next;
	int where;
} *first[100001], a[200001];

int n, l, size[100001];
long long f[100001], v[100001];
bool b[100001];
inline void makelist(int x, int y) {
	a[++l].where = y;
	a[l].next = first[x];
	first[x] = &a[l];
}
inline void up(int i) {
	size[i] = 1;
	b[i] = true;
	for (node *x = first[i]; x; x = x->next)
		if (!b[x->where]) {
			up(x->where);
			size[i] += size[x->where];
			f[i] += f[x->where] + size[x->where];
		}
}
inline void down(int i) {
	b[i] = true;
	for (node *x = first[i]; x; x = x->next) 
		if (!b[x->where]) {
			v[x->where] = v[i] + f[i] - f[x->where] - size[x->where] + n - size[x->where];
			down(x->where);
		}
}
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		makelist(x, y);
		makelist(y, x);
	}
	memset(b, false, sizeof(b));
	up(1);
	memset(b, false, sizeof(b));
	down(1);
	for (int i = 1; i <= n; i++)
		printf("%lld\n", f[i] + v[i]);
}