#include <bits/stdc++.h>

using namespace std;

int n, a[100001];
typedef long long ll;
ll k;
ll calc (ll x) {
	ll res = 0;
	for (int i = 1; i <= n; i++)
		res += max(0LL, x - a[i]);
	return res;
}
int main(void) {
	scanf("%d%lld", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	ll L = 1, R = 1e14;
	while (L + 1 < R) {
		ll M = (L + R) / 2;
		if (calc(M) <= k)
			L = M;
		else
			R = M;
	}
	printf("%lld", L);
	return 0;
}