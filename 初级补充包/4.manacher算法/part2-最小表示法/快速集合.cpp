#include <bits/stdc++.h>

using namespace std;

int n, a[100001], b[100001];

bool check(double x) {
	double L = -1e10, R = 1e10;
	for (int i = 1; i <= n; i++) {
		double l = a[i] - b[i] * x, r = a[i] + b[i] * x;
		L = max(L, l);
		R = min(R, r);
	}
	if (L > R)
		return false;
	return true;
}
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf ("%d%d", &a[i], &b[i]);
	double L = 0, R = 50000;
	for (int i = 1; i <= 100; i++) {
		double M = (L + R) / 2;
		if (check(M))
			R = M;
		else
			L = M;
	}
	printf("%.10f\n", R);
}