#include <bits/stdc++.h>

using namespace std;

const int b1 = 1037, b2 = 1111, p1 = 9999971, p2 = 9999973;
int n, a[100001], s[2000002];
long long c1[200002], c2[200002], h1[200002], h2[200002], H1[200002], H2[200002];
pair<int, int> calc1(int l, int r) {
	return {(H1[l] - H1[r + 1] * c1[r - l + 1] % p1 + p1) % p1, (H2[l] - H2[r + 1] * c2[r - l + 1] % p2 + p2) % p2};
}
pair<int, int> calc2(int l, int r) {
	return {(h1[r] - h1[l - 1] * c1[r - l + 1] % p1 + p1) % p1, (h2[r] - h2[l - 1] * c2[r - l + 1] % p2 + p2) % p2};
}
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	int m = 0;
	s[++m] = 1001;
	for (int i = 1; i <= n; i++)
		s[++m] = a[i], s[++m] = 1001;
	c1[0] = c2[0] = 1;
	for (int i = 1; i <= m; i++)
		c1[i] = c1[i - 1] * b1 % p1, c2[i] = c2[i - 1] * b2 % p2;
	for (int i = 1; i <= m; i++)
		h1[i] = (h1[i - 1] * b1 % p1 + s[i]) % p1,
		h2[i] = (h2[i - 1] * b2 % p2 + s[i]) % p2;
	for (int i = m; i; --i)
		H1[i] = (H1[i + 1] * b1 % p1 + s[i]) % p1,
		H2[i] = (H2[i + 1] * b2 % p2 + s[i]) % p2;
	int ans = 0;
	for (int i = 1; i <= m; i++) {
		int L = 0, R = min(i, m - i + 1) + 1;
		while (L + 1 < R) {
			int M = (L + R) / 2;
			if (calc1(i, i + M - 1) == calc2(i - M + 1, i))
				L = M;
			else
				R = M;
		}
		ans = max(ans, L);
	}
	printf("%d\n", ans - 1);
}