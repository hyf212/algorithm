#include <bits/stdc++.h>

using namespace std;

int n, m, w[505][501], f[501];

int main(void) {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &w[i][j]);
	for (int i = 1; i <= n; i++)
		for (int j = m; j >= 0; j--)
			for (int k = 0; k <= j; k++)
				f[j] = max(f[j],f[j - k] + w[i][k]);
	printf("%d", f[m]);
	return 0;
}