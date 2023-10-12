#include <bits/stdc++.h>

using namespace std;

int n, m, f[256], v[256], a[100001];
bool b[256];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < 1 << m; i++) {
		int cnt = 0;
		for (int j = 1; j <= m; j++)
			if (i & (1 << (j - 1)))
				++cnt;
		if (cnt <= m / 2)
			b[i] = true;
	}
	memset(f, 128, sizeof(f));
	f[0] = 0;
	for (int i = 1; i <= n; i++) {
		memset(v, 128, sizeof(v));
		for (int j = 0; j < 1 << m; j++)
			if (f[j] >= 0) {
				v[j / 2] = max(v[j / 2], f[j]);
				if (b[j / 2 + (1 << (m - 1))])
					v[j / 2 + (1 << (m - 1))] = max(v[j / 2 + (1 << (m - 1))], f[j] + a[i]);
			}
		memcpy(f, v, sizeof(f));
	}
	int ans = 0;
	for (int i = 1; i < 1 << m; i++)
		ans = max(ans, f[i]);
	printf("%d\n", ans);
}