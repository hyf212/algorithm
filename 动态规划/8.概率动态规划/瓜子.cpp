#include <bits/stdc++.h>

using namespace std;

int n;

long long f[2001][4001], a[4001];
const int p = 998244353;

long long rp(long long now, int k) {
	long long ans = 1;
	for (; k; k >>= 1) {
		if (k & 1)
			ans *= now, ans %= p;
		now *= now;
		now %= p;
	}
	return ans;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= 2 * n; i++)
		a[i] = rp(i, p - 2);
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= 2 * n - 2; j++) {
			f[i][j] = f[i - 1][j + 2] * i % p * a[i + j] % p + 1;
			if (j)
				f[i][j] += f[i][j - 1] * j % p * a[i + j] % p;
		}
	printf("%lld\n", f[n][0]);
	return 0;
}