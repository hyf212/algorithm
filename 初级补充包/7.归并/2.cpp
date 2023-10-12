#include <bits/stdc++.h>

using namespace std;

struct Node {
	int x, y;
}a[101];
int t, n;
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d%d", &a[i].x, &a[i].y);
			x1 = min(x1, a[i].x);
			x2 = max(x2, a[i].x);
			y1 = min(y1, a[i].y);
			y2 = max(y2, a[i].y);
		}
		printf("%d\n", 2 * (x2 - x1 + y2 - y1));
	}
}