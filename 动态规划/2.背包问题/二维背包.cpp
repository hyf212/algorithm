/*#include<bits/stdc++.h>

using namespace std;

int n, m, k,v[101], w[101], t[101], f[101][101][101];

int main(void) {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d%d%d", &v[i], &w[i], &t[i]);
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= m; j++)
			for (int x = 0; x <= k; x++) {
				f[i][j][x] = f[i - 1][j][x];
				if (j >= v[i] && x >= t[i])
					f[i][j][x] = max(f[i][j][x], f[i - 1][j - v[i]][x - t[i]] + w[i]);
			}
	printf("%d", f[n][m][k]);			
}*/
#include<bits/stdc++.h>

using namespace std;

int n, m, k,v[101], w[101], t[101], f[101][101];

int main(void) {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d%d%d", &v[i], &w[i], &t[i]);
	for (int i = 1; i <= n; i++)
		for (int j = m; j >= v[i]; j--)
			for (int x = k; x >= t[i]; x--)
				f[j][x] = max(f[j][x], f[j - v[i]][x - t[i]] + w[i]);
	printf("%d", f[m][k]);
	return 0;			
}