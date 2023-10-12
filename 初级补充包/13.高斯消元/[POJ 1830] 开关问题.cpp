#include <bits/stdc++.h>

using namespace std;

const int N = 30;
int k, n, a[N][N], b[N], c[N], d[N];
inline void gauss() {
	int l = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = l; j <= n; j++)
			if (a[j][i]) {
				for (int k = i; k <= n; k++)
					swap(a[l][k], a[j][k]);
				swap(b[j], b[l]);
				break;
			}
		if (!a[l][i])
			continue;
		for (int j = 1; j <= n; j++)
			if (j != l && a[j][i]) {
				for (int k = i; k <= n; k++)
					a[j][k] ^= a[l][k];
				b[j] ^= b[l];
			}
		++l;
	}
	for (int i = l; i <= n; i++)
		if (b[i]) {
			printf("-1\n");
			return ;
		}
	printf("%d\n", 1 << (n - l + 1));
} 
int main() {
	scanf("%d", &k);
	for ( ; k--; ) {
		scanf("%d", &n);
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		for (int i = 1; i <= n; i++)
			scanf("%d", &c[i]);
		for (int i = 1; i <= n; i++)
			scanf("%d", &d[i]);
		for (int i = 1; i <= n; i++)
			b[i] = c[i] ^ d[i];
		for (int i = 1; i <= n; i++) a[i][i] = 1;
		int x, y;
		while (scanf("%d%d", &x, &y)) {
			if (x == 0 && y == 0) break;
			a[y][x] = 1;
		}
		gauss();
	}
}