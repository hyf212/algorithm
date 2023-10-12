#include <bits/stdc++.h>

using namespace std;

int n, a[200001];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	sort(a + 1, a + 1 + n);
	int ans = 1;
	for (int i = 2; i <= n; i++) {
		if (a[i] == a[i - 1])
			ans++;
		else {
			printf("%d %d\n", a[i - 1], ans);
			ans = 1;
		}
	}
	printf("%d %d\n", a[n], ans);
	return 0;
}