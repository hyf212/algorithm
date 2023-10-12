/*#include<bits/stdc++.h>

using namespace std;

int n, a[505], s[505], f[505][505];

int solve(int l, int r) {
	if (l == r)
		return f[l][r] = 0;
	if (f[l][r] != -1)
		return f[l][r];
	int ans = 1 << 30;
	for (int i = l; i < r; i++)
		ans = min(ans, solve(l, i) + solve(i + 1, r));
	return f[l][r] = ans + s[r] - s[l - 1];
}
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)
		s[i] = s[i - 1] + a[i];
	memset(f, 255, sizeof(f));
	printf("%d", solve(1, n));
	return 0;
}*/
#include <bits/stdc++.h>

using namespace std;

int n, a[505], s[505], f[505][505];

int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	memset(f, 127, sizeof(f));
	for (int i = 1; i <= n; i++) {
		s[i] = s[i - 1] + a[i];
		f[i][i] = 0;
	}
	for (int i = 1; i < n; i++)
		for (int j = 1; j <= n - i; j++)
			for (int k = j; k < j + i; k++)
				f[j][j + i] = min(f[j][j + i], f[j][k] + f[k + 1][j + i] + s[j + i] - s[j - 1]);
	printf("%d", f[1][n]);
	return 0;
}