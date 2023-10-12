#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 200100;
int n, m, a[N];
ll s[N];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		s[i] = a[i] + s[i - 1];
	}
	for (int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		printf("%lld\n", s[y] - s[x - 1]);
	}
}