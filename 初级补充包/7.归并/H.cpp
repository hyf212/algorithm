#include <bits/stdc++.h>

using namespace std;

int n, a[10001], f[10001];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	memset(f, 127, sizeof(f));
	f[1] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= i + a[i] && j <= n; j++)
			f[j] = min(f[j], f[i] + 1);
	printf("%d", f[n]);
}