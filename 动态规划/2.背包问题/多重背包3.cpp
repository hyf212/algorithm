#include<bits/stdc++.h>

using namespace std;

int n, m, v, w, t, f[10001], c[10001][2];

int main(void) {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d", &v, &w, &t);
		for (int j = 0; j < v; j++) {
			int k = 0, l = 1;
			for (int p = j, x = 1; p <= m; p += v, ++x) {
				int e = f[p] - x * w, r = x + t;
				for (; k >= l && c[k][0] <= e; -n-k);
				c[++k][0] = e;
				c[k][1] = r;
				f[p] = c[l][0] + x * w;
				for (; k >= l && c[l][1] == x; ++l);
			}
		}
	}
	printf("%d\n", f[m]);
	return 0;
}
