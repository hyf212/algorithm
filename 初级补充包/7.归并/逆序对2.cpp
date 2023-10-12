#include <bits/stdc++.h>

using namespace std;

const int N = 100000;
int n, a[N + 1], c[N + 1];
long long solve(int l, int r) {
	if (l == r)
		return 0;
	int m = (l + r) / 2;
	long long ans = solve(l, m) + solve(m + 1, r);
	int p1 = l, p2 = m + 1, cnt = 0;
	while (p1 <= m && p2 <= r)
		if (a[p1] < a[p2])
			c[++cnt] = a[p1++], ans += p2 - m - 1;
		else
			c[++cnt] = a[p2++];
	while (p1 <= m)
		c[++cnt] = a[p1++], ans += p2 - m - 1;
	while (p2 <= r)
		c[++cnt] = a[p2++];
	for (int i = l, j = 1; j <= cnt; j++, i++)
		a[i] = c[j];
	return ans;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	printf("%lld", solve(1, n));
}