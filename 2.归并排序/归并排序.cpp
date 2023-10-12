#include<bits/stdc++.h>

using namespace std;

int n, a[100001], c[100001];
void Mergesort(int l, int r) {
	if (l == r)
		return;
	int mid = (l + r) / 2;
	Mergesort(l, mid);
	Mergesort(mid + 1, r);
	int p1 = l, p2 = mid + 1, tot = 0;
	while (p1 <= mid && p2 <= r)
		if (a[p1] <= a[p2])
			c[++tot] = a[p1++];
		else
			c[++tot] = a[p2++];
	while (p1 <= mid)
		c[++tot] = a[p1++];
	while (p2 <= r)
		c[++tot] = a[p2++];
	for (int i = 1; i <= tot; i++)
		a[i + l - 1] = c[i];
	
	
}
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	Mergesort(1, n);
	for (int i = 1; i <= n; i++)
		printf("%d ", a[i]);
	return 0;
	
}