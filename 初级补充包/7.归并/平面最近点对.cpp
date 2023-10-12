#include <bits/stdc++.h>

using namespace std;

struct Node {
	double x, y;
	bool operator < (const Node &A) const {
		return x < A.x;
	}
} a[200001], c[200001];

int n;

double solve(int l, int r) {
	if (l == r)
		return 1e10;
	int m = (l + r) / 2;
	double d = min(solve(l, m), solve(m + 1, r));
	int cnt = 0;
	for (int i = l; i <= r; i++)
		if (abs(a[i].x - a[m].x) < d)
			c[++cnt].x = a[i].y, c[cnt].y = a[i].x;
	sort(c + 1, c + 1 + cnt);
	for (int i = 1; i <= cnt; i++)
		for (int j = i + 1; j <= cnt && c[j].x - c[i].x < d; j++)
				d = min(d, sqrt((c[i].x - c[j].x) * (c[i].x - c[j].x) + (c[i].y - c[j].y) * (c[i].y - c[j].y)));
	return d;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%lf%lf",&a[i].x, &a[i].y);
	sort(a + 1, a + 1 + n);
	printf("%.10lf", solve(1, n));
}