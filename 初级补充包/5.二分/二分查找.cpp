#include <bits/stdc++.h>

using namespace std;

const int N = 200001;
int n, m, a[N];

int calc1(int x) {
	int L = 0, R = n + 1;
	while (L + 1 < R) {
		int mid = (R - L) / 2 + L;
		if (a[mid] < x)
			L = mid;
		else
			R = mid;
	}
	return L;
}
int calc2(int x) {
	int L = 0, R = n + 1;
	while (L + 1 < R) {
		int mid = (R - L) / 2 + L;
		if (a[mid] <= x)
			L = mid;
		else
			R = mid;
	}
	return L;
}
int main(void) {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) 
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	while (m--) {
		int x;
		scanf("%d", &x);
		printf("%d %d %d\n", calc1(x), calc2(x) - calc1(x), n - calc2(x));
	}
	return 0;
}