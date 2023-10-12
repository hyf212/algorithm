#include<bits/stdc++.h>

using namespace std;

int n, f[1001], a[1001];
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) {
		f[i] = 1;
		for (int j = 1; j < i; j++)
			if (a[j] < a[i])
				f[i] = max(f[i], f[j] + 1);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans = max(ans, f[i]);
	printf("%d\n", ans);
	return 0;
}