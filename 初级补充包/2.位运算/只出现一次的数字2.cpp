#include <bits/stdc++.h>

using namespace std;

const int N = 1000001;
int n, a[N];

int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int v = 0;
	for (int i = 0; i < n; i++)
		v ^= a[i];
	int c = 0;
	for (; v; v >>= 1)
		c++;
	int x = 0, y = 0;
	for (int i = 0; i < n; i++)
		if ((a[i] >> (c - 1)) & 1)
			y ^= a[i];
		else
			x ^= a[i];
	printf("%d %d\n", x, y);
	return 0;
}