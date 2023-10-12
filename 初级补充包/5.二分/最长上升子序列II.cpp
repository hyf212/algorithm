#include <bits/stdc++.h>

using namespace std;

int n, a[100001], c[100001], y;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	  	scanf("%d", &a[i]);
	y = 0;
	for (int i = 1; i <= n; i++)
		if (a[i] > c[y])
			c[++y] = a[i];
		else {
			int L = 0, R = y;
			while (L + 1 < R) {
				int M = (L + R) / 2;
				if (c[M] < a[i])
					L = M;
				else
					R = M;
			}
			c[R] = a[i];
		}
	printf("%d\n", y);
}