#include<bits/stdc++.h>

using namespace std;

int n, m, f[20001], v[20001], w[20001], l[20001];

int main(void) {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d%d%d", &v[i], &w[i], &l[i]);
	for (int i = 1; i <= n; i++) {
		int res = l[i];
		for (int j = 1; j <= res; res -= j, j *= 2)
			for (int k = m; k >= v[i] * j; k--)
				f[k] = max(f[k], f[k - v[i] * j] + j * w[i]);
		for (int j = m; j >= v[i] * res; j--)
			f[j] = max(f[j], f[j - v[i] * res] + w[i] * res);
	}

	printf("%d", f[m]);
	return 0;
}