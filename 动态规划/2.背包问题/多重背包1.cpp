#include<bits/stdc++.h>

using namespace std;

int n, m, f[1001], v[1001], w[1001], l[1001];

int main(void) {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d%d%d", &v[i], &w[i], &l[i]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= l[i]; j++)
			for (int k = m; k >= v[i]; k--)
				f[k] = max(f[k], f[k - v[i]] + w[i]);
	printf("%d", f[m]);
	return 0;
}