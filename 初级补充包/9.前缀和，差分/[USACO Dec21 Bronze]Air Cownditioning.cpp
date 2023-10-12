#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100010;
int n, a[N], b[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)
		scanf("%d", &b[i]);
	for (int i = 1; i <= n; i++)
		a[i] -= b[i];
	int ans = 0;
	for (int i = 1; i <= n + 1; i++)
		ans += max(a[i] - a[i - 1], 0);
	printf("%d\n", ans);
}