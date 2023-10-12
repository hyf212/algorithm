/*#include<bits/stdc++.h>

using namespace std;

int n, m, dp[1001][1001], v[1001], w[1001];

int main(void) {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &v[i], &w[i]);
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= m; j++)
			if (j < v[i])
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - v[i]] + w[i]);
	printf("%d", dp[n][m]);
}*/
#include<iostream>

using namespace std;

int n, m, f[1001], v[1001], w[1001];

int main(void) {
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &v[i], &w[i]);
	for (int i = 1; i <= n; i++)
		for (int j = v[i]; j <= m; j++)
			f[j] = max(f[j], f[j - v[i]] + w[i]);
	printf("%d", f[m]);
	return 0;
}