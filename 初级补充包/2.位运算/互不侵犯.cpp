#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int n, m, v[1001];
ll f[10][1001][82];
bool b[1001];

int main(void) {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < 1 << n; i++) {
		v[i] = 0;
		for (int j = i; j; j = j & (j - 1))
			v[i]++;
		b[i] = ((i & (i << 1)) == 0);
	}
	memset(f, 0, sizeof(f));
	f[0][0][0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < 1 << n; j++)
			for (int k = 0; k <= n * n; k++)
				if (f[i - 1][j][k])
					for (int l = 0; l < 1 << n; l++)
						if (((l & j) == 0) && (((l >> 1) & j) == 0) & (((l << 1) & j) == 0) && b[l])
							f[i][l][k + v[l]] += f[i - 1][j][k];
	ll ans = 0;
	for (int i = 0; i < 1 << n; i++)
		ans += f[n][i][m];
	printf("%lld", ans);
}