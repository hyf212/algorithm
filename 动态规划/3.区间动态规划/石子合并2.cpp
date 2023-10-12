#include <bits/stdc++.h>

using namespace std;

int n, a[501], f[501][501], s[501];

int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		a[n + i] = a[i];
	}
	n *= 2;
	for (int i = 1; i <= n; i++)
		s[i] = s[i - 1] + a[i];
	memset(f, 127, sizeof(f));
	for (int i = 1; i <= n; i++)
		f[i][i] = 0;
	for (int i = 1; i < n; i++)
		for (int j = 1; j <= n - i; j++)
			for (int k = j; k < j + i; k++)
				f[j][i + j] = min(f[j][i + j], f[j][k] + f[k + 1][i + j] + s[i + j] - s[j - 1]);
	int ans = 1 << 30;
	for (int i = 1; i <= n / 2; i++)
		ans = min(ans, f[i][i + n / 2 - 1]);
	printf("%d\n", ans);
	return 0;
}