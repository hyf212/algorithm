#include <bits/stdc++.h>

using namespace std;

int n, A, R, M, a[100001];

long long f(int x) {
	long long y = 0, z = 0;
	for (int i = 1; i <= n; i++)
		if (a[i] <= x)
			y += x - a[i];
		else
			z += a[i] - x;
	long long res = min(y, z) * M;
	if (y > z)
		res += (y - z) * A;
	if (z > y)
		res += (z - y) * R;
	return res;
}
int main() {
	scanf("%d%d%d%d", &n, &A, &R, &M);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	M = min(M, A + R);
	int l = 0, r = 1e9;
	while (l + 2 < r) {
		int M1 = (r - l) / 3 + l;
		int M2 = (r - l) / 3 * 2 + l;
		if (f(M1) > f(M2))
			l = M1;
		else
			r = M2;
	}
	long long ans = f(l);
	for (int i = l + 1; i <= r; i++)
		ans = min(ans, f(i));
	printf("%lld", ans);
	return 0;
}