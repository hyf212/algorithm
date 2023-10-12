#include <bits/stdc++.h>

using namespace std;

int n, m;
long long f[101][101], v[101], a[101];
vector<int> c[101];
const int p = 1000000007;
long long rp(long long now, int k) {
	long long res = 1;
	for (; k; k >>= 1, now *= now, now %= p)
		if (k & 1)
			res *= now, res %= p;
	return res;
}
inline void gsxy() {
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++)
			if (f[j][i]) {
				for (int k = i; k <= n; k++)
					swap(f[i][k], f[j][k]);
				swap(v[j], v[i]);
				break;
			}
		for (int j = i + 1; j <= n; j++)
			if (f[j][i]) {
				long long delta = f[j][i] * rp(f[i][i], p - 2) % p;
				for (int k = i; k <= n; k++) {
					f[j][k] -= f[i][k] * delta % p;
					if (f[j][k] < 0)
						f[j][k] += p;
				}
				v[j] -= v[i] * delta % p;
				if (v[j] < 0)
					v[j] += p;
			}
	}
	for (int i = n; i; --i) {
		for (int j = i + 1; j <= n; j++) {
			v[i] -= f[i][j] * a[j] % p;
			if (v[i] < 0)
				v[i] += p;
		}
		a[i] = v[i] * rp(f[i][i], p - 2) % p;
	}
}
int main(void) {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		c[x].push_back(y);
	}
	for (int i = 1; i < n; i++) {
		f[i][i] = 1, v[i] = 1;
		int l = c[i].size();
		for (int j = 0; j < l; j++)
			f[i][c[i][j]] = p - 1 * rp(l, p - 2);
	}
	f[n][n] = 1;
	gsxy();
	printf("%lld\n", a[1]);
}