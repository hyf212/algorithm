/*#include<bits/stdc++.h>

using namespace std;

struct Node {
	int where;
	Node *next; 
} *first[100001], a[100001];

int n, l, f[100001];

inline void makelist(int x, int y) {
	a[++l].where = y;
	a[l].next = first[x];
	first[x] = &a[l];
}
inline void solve(int x) {
	f[x] = 1;
	for (Node *p = first[x]; p; p = p->next) {
		solve(p->where);
		f[x] += f[p->where];
	}
}
int main(void) {
	scanf("%d", &n);
	memset(first, 0, sizeof(first));
	for (int i = 2; i <= n; i++) {
		int x;
		scanf("%d", &x);
		makelist(x, i);
	}
	solve(1);
	for (int i = 1; i <= n; i++)
		printf("%d ", f[i]);
	return 0;
}*/
#include<bits/stdc++.h>

using namespace std;

struct Node {
	int where;
	Node *next; 
} *first[100001], a[100001];

int n, l, f[100001], c[100001];

inline void makelist(int x, int y) {
	a[++l].where = y;
	a[l].next = first[x];
	first[x] = &a[l];
}
int main(void) {
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		int x;
		scanf("%d", &x);
		makelist(x, i);
	}
	int l = 1, r = 0;
	c[++r] = 1;
	while (l <= r) {
		int m = c[l];
		for (Node *p = first[m]; p; p = p->next)
			c[++r] = p->where;
		++l;
	}
	for (int i = n; i; --i) {
		int m = c[i];
		f[m] = 1;
		for (Node *p = first[m]; p; p = p->next)
			f[m] += f[p->where];
	}
	for (int i = 1; i <= n; i++)
		printf("%d ", f[i]);
	return 0;
}