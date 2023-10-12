#include<bits/stdc++.h>

using namespace std;

int n, m, a[1001], b[1001], f[1001][1001];

int main(void) {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= m; i++)
		scanf("%d", &b[i]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			f[i][j] = max(f[i][j - 1], f[i - 1][j]);
			if (a[i] == b[j])
				f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
		}
	printf("%d", f[n][m]);
	return 0;
}