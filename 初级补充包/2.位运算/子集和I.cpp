#include <bits/stdc++.h>

using namespace std;

int n;
long long f[1 << 16];
const int p = 1000000007;
int main(void) {
	scanf("%d", &n);
	f[0] = 1;
	for (int i = 1; i < 1 << n; i++) {
		f[i] = 1;
		for (int j = (i - 1) & i; j; j = (j - 1) & i)
			f[i] += f[j], f[i] %= p;
		f[i] = 1LL * f[i] * i % p;
	}
	for (int i = 0; i < 1 << n; i++)
		printf("%lld ", f[i]);
	return 0;
}