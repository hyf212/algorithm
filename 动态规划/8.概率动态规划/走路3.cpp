/*#include <bits/stdc++.h>

using namespace std;

int n, m;
long long f[101][101];
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
	f[1][0] = 1;
	for (int i = 1; i <= n; i++) {
		int l = c[i].size();
		for (int j = 0; j < n; j++)
			if (f[i][j])
				for (int k = 0; k < l; k++)
					f[c[i][k]][j + 1] += f[i][j] * rp(l, p - 2),
					f[c[i][k]][j + 1] %= p;
	}
	long long ans = 0;
	for (int i = 1; i < n; i++)
		ans += f[n][i] * i, ans %= p;
	printf("%lld\n", ans);
	return 0;
}*/

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
	f[n] = 0;
	for (int i = n - 1; i; i--) {
		f[i] = 1;
		int l = c[i].size();
		for (int j = 0; j < l; j++)
			f[i] += f[c[i][j]] * rp(l, p - 2), f[i] %= p;
	}
	printf("%lld", f[1]);
	return 0;
}