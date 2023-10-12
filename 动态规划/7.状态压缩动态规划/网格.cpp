#include <bits/stdc++.h>

using namespace std;

int n, m, f[1 << 18], v[1 << 18];
const int p = 1000000007;
int main(void) {
	scanf("%d%d", &n, &m);
	memset(f, 0, sizeof(f));
	f[0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			memset(v, 0,sizeof(v));
			for (int k = 0; k < 1 << m; k++)
				if (f[k])
					if (k & (1 << (j - 1)))
						v[k - (1 << (j - 1))] += f[k], v[k - (1 << (j - 1))] %= p;
					else {
						if (i != n)
							v[k + (1 << (j - 1))] += f[k], v[k + (1 << (j - 1))] %= p;
						if (j != m && !(k & (1 << j)))
							v[k + (1 << j)] += f[k], v[k + (1 << j)] %= p;
				}
		memcpy(f, v, sizeof(f));
		}
	printf("%d\n", f[0]);
	return 0;
}