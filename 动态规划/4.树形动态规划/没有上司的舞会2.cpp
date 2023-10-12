#include<bits/stdc++.h>

using namespace std;

struct Node {
	int where;
	Node *next;
} *first[100001], a[100001];

int n ,m, v[501], l;
long long f[501][501][2];
inline void makelink(int x, int y) {
	a[++l].where = y;
	a[l].next = first[x];
	first[x] = &a[l];
}
inline void solve(int i) {
	for (Node *p = first[i]; p; p = p->next) {
		solve(p->where);
		for (int j = m; j >= 0; --j)
			for (int k = 0; k <= j; k++) {
				f[i][j][0] = max(f[i][j][0], f[i][j - k][0] + max(f[p->where][k][0], f[p->where][k][1]));
				f[i][j][1] = max(f[i][j][1], f[i][j - k][1] + f[p->where][k][0]);
			}
	}
	for (int j = m; j; j--)
		f[i][j][1] = f[i][j - 1][1] + v[i];
	f[i][0][1] = 0; 
}
int main(void) {
	scanf("%d%d", &n, &m);
	memset(first, 0, sizeof(first));
	for (int i = 2; i <= n; i++) {
		int x;
		scanf("%d", &x);
		makelink(x, i);
	}
	for (int i = 1; i <= n; i++)
		scanf("%d", &v[i]);
	solve(1);
	printf("%lld", max(f[1][m][0], f[1][m][1]));
}