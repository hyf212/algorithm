#include <bits/stdc++.h>

using namespace std;

const int N = 200100;
int n, m, a[N], d[N];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		d[i] = a[i] - a[i - 1];
	}
	for (int i = 1; i <= m; i++) {
		int l, r;
		scanf("%d%d", &l, &r);
		d[l] += 1; d[r + 1] -= 1;
	}
	for (int i = 1; i <= n; i++)
		a[i] = a[i - 1] + d[i];
	for (int i = 1; i <= n; i++)
		printf("%d ", a[i]);
	return 0;
}