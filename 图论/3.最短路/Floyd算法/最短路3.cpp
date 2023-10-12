#include <bits/stdc++.h>

using namespace std;

int n, m, q, f[301][301];

int main() {
	scanf("%d%d%d", &n, &m, &q);
	memset(f, 127, sizeof(f));
	for (int i = 1; i <= n; i++)
		f[i][i] = 0;
	for (int i = 1; i <= m; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		f[x][y] = z;
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (f[i][k] < 1 << 30 && f[k][j] < 1 << 30)
					f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
	for (int i = 1; i <= q; i++) {
		int s, t;
		scanf("%d%d", &s, &t);
		if (f[s][t] < 1 << 30)
			printf("%d\n", f[s][t]);
		else
			printf("-1\n");
			
	}
}