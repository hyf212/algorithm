#include <bits/stdc++.h>

using namespace std;

int n, k[100001], b[100001], m;

long long calc(int x) {
	long long res = 0;
	for (int i = 1; i <= n; i++)
		if (x >= b[i])
			res += (x - b[i]) / k[i] + 1;
	return res;
}
long long sum(int x) {
	long long res = 0;
	for (int i = 1; i <= n; i++)
		if (x >= b[i]) {
			int y = (x - b[i]) / k[i] + 1;
			res += 1LL * (b[i] + k[i] * (y - 1) + b[i]) * y / 2;
		}
	return res;
}
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &k[i], &b[i]);
	scanf("%d", &m);
	int L = 0, R = 1e9;
	while (L + 1 < R) {
		int M = (L + R) / 2;
		if (calc(M) <= m)
			L = M;
		else
			R = M;
	}
	printf("%lld", sum(L) + 1LL * (m - calc(L)) * (L + 1));
	return 0;
}