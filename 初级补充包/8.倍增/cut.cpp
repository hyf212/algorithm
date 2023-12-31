#include <bits/stdc++.h>

using namespace std;

const int N = 100000;
int n, q, a[N + 1], f[N + 1][21], v[N + 1];
vector<int> c[N + 1];
bool b[N + 1];
int main() {
	memset(b, false, sizeof(b));
	for (int i = 2; i <= 100000; i++)
		if (!b[i]) {
			c[i].push_back(i);
			for (int j = i + i; j <= 100000; j += i) {
				b[j] = true;
				c[j].push_back(i);
			}
		}
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	f[n + 1][0] = n + 1;
	memset(v, 127, sizeof(v));
	for (int i = n; i; --i) {
		f[i][0] = f[i + 1][0];
		for (auto j : c[a[i]]) {
			f[i][0] = min(f[i][0], v[j]);
			v[j] = i;
		}
	}
	for (int i = 1; i <= 20; i++)
		for (int j = 1; j <= n; j++)
			if (f[j][i - 1] <= n)
				f[j][i] = f[f[j][i - 1]][i - 1];
			else
				f[j][i] = n + 1;
	while (q--) {
		int l, r;
		scanf("%d%d", &l, &r);
		int ans = 0;
		for (int i = 20; i >= 0; --i)
			if (f[l][i] <= r) {
				ans += (1 << i);
				l = f[l][i];
			}
		++ans;
		printf("%d\n", ans);
	}
}