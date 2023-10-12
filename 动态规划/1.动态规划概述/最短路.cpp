#include<bits/stdc++.h>

using namespace std;

int n, m, f[1001], a[1001][1001];
int main(void) {
	scanf("%d%d", &n, &m);
	memset(a, 127, sizeof(a));
	for (int i = 1; i <= m; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		a[x][y] = min(a[x][y], z);
	}
	memset(f, 127, sizeof(f));
	f[1] = 0;
	for (int i = 2; i <= n; i++)
		for (int j = 1; j < i; j++)
			if (a[j][i] < 1 << 30 && f[j] < 1 << 30)
				f[i] = min(f[i], f[j] + a[j][i]);
	printf("%d", f[n]);
	return 0;
}