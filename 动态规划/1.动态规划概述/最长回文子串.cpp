#include<bits/stdc++.h>

using namespace std;

int n, a[1001], f[1001][1001], ans = 0;

int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) {
		f[i][i] = 1;
		if (i + 1 <= n && a[i] == a[i + 1]) {
			f[i][i + 1] = 1;
			ans = 2;
		}
	}
	for (int L = 3; L <= n; L++)
		for (int i = 1; i + L - 1 <= n; i++) {
			int j = i + L - 1;
			if (a[i] == a[j] && f[i + 1][j - 1] == 1) {
				f[i][j] = 1;
				ans = L;
			}
		}

	printf("%d", ans);
}