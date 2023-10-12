#include<bits/stdc++.h>

using namespace std;

int n, m  = 10, a[100001], sa[100001], v[100001], r[100001], c[10];

inline void countingsort() {
	memset(c, 0, sizeof(c));
	for (int i = 1; i <= n; i++)
		c[v[i]]++;
	for (int i = 1; i < 10; i++)
		c[i] += c[i - 1];
	for (int i = n; i; i--)
		r[sa[i]] = c[v[sa[i]]]--;
	for (int i = 1; i <= n; i++)
		sa[r[i]] = i;
}
inline void radixsort() {
	for (int i = 1; i <= n; i++)
		sa[i] = i;
	int x = 1;
	for (int i = 1; i <= m; i++, x *= 10) {
		for (int j = 1; j <= n; j++)
			v[j] = a[j] / x % 10;
		countingsort();
	}
	for (int i = 1; i <= n; i++)
		printf("%d ", a[sa[i]]);
	printf("\n");
}
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	radixsort();
}