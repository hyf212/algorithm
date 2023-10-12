#include <bits/stdc++.h>

using namespace std;

int n, m, a[1001][1001];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		if (x == y || a[x][y] == 1) {
			printf("No");
			return 0;
		}
		a[x][y] = a[y][x] = 1;
	}
	printf("Yes");
	return 0;
}