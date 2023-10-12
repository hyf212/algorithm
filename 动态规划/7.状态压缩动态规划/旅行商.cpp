#include <bits/stdc++.h>

using namespace std;

int n, a[19][19], f[1 << 18][19];

int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &a[i][j]);
	memset(f, 127, sizeof(f));
	f[1][1] = 0;
	for (int i = 1; i < 1 << n; i++)
		for (int j = 1; j <= n; j++)
			if (f[i][j] < 1 << 30)
				for (int k = 1; k <= n; k++)
					if (!(i & (1 << (k - 1))))
						f[i + (1 << (k - 1))][k] = min(f[i + (1 << (k - 1))][k], f[i][j] + a[j][k]);
	int ans = 1 << 30;
	for (int i = 2; i <= n; i++)
		ans = min(ans, f[(1 << n) - 1][i] + a[i][1]);
	printf("%d", ans);
	return 0;
}