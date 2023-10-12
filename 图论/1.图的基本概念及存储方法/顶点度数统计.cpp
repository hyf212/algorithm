#include <bits/stdc++.h>

using namespace std;

int n, m, d[1001];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		++d[x], ++d[y];
	}
	for (int i = 1; i <= n; i++)
		printf("%d ", d[i]);
}