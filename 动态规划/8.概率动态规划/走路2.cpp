#include <bits/stdc++.h>

using namespace std;

int n, m;
long long f[101];
const int p = 1000000007;
vector<int> c[101];

long long rp(long long now, int k) {
	long long res = 1;
	for (; k; k >>= 1, now *= now, now %= p) //倍增
		if (k & 1)
			res *= now, res %= p;
	return res;
} 
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		c[x].push_back(y);
	}
	memset(f, 0, sizeof(f));
	f[1] = 1;
	for (int i = 1; i <= n; i++) {
		int l = c[i].size();
		for (int j = 0; j < l; j++)
			f[c[i][j]] += f[i] * rp(l, p - 2), f[c[i][j]] %= p;
	}
	printf("%lld", f[n]);
	return 0;
}