#include <bits/stdc++.h>

using namespace std;

const int N = 2000000;
int n, p[2 * N + 2], f[2 * N + 2], v[2 * N + 2];
char s[N + 2], t[2 * N + 3];
const int mod = 51123987;

void manacher() {
	n = strlen(s + 1);
	int m = 0;
	t[++m] = '$';
	for (int i = 1; i <= n; i++)
		t[++m] = s[i], t[++m] = '$';
	int M = 0, R = 0;
	for (int i = 1; i <= m; i++) {
		if (i > R)
			p[i] = 1;
		else
			p[i] = min(p[2 * M - i], R - i + 1);
		while (i - p[i] > 0 && i + p[i] <= m &&t[i - p[i]] == t[i + p[i]])
			++p[i];
		if (i + p[i] - 1 > R)
			M = i, R = i + p[i] - 1;
	}
	long long x = 0;
	for (int i = 1; i <= m; i++) {
		int l = (i - p[i] + 2) / 2, r = i / 2;
		++v[l]; --v[r + 1];
		l = (i + 1) / 2; r = (i + p[i] - 2) / 2;
		++f[l]; --f[r + 1];
		x += r - l + 1;
	}
	for (int i = 1; i <= n + 1; i++)
		v[i] += v[i - 1];
	for (int i = 1; i <= n; i++)
		f[i] += f[i - 1];
	for (int i = n - 1; i; i--)
		v[i] += v[i + 1], v[i] %= mod;
	long long ans = 0;
	if (x & 1)
		ans = x % mod *((x - 1) / 2 % mod) % mod;
	else
		ans = x / 2 % mod * ((x - 1) % mod) % mod;
	for (int i = 1; i <= n; i++) {
		ans -= 1LL * f[i] * v[i + 1] % mod;
		if (ans < 0)
			ans += mod;
	}
	printf("%lld\n", ans);
}
int main(void) {
	scanf("%d%s", &n, s + 1);
	manacher();
	return 0;
}