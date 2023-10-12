#include<bits/stdc++.h>

using namespace std;

struct Node {
	int x, y;
	bool operator < (const Node &A) const {
		if (x != A.x)
			return x < A.x;
		return y < A.y;
	}
} a[100001];
int n;
inline void quicksort(int l, int r) {
	if(l >= r)
		return;
	swap(a[l], a[l + rand()%(r - l + 1)]);
	Node x = a[l];
	int i = l, j = r;
	while (i < j) {
		while (i < j && x < a[j])
			--j;
		if (i < j)
			a[i++] = a[j];
		while (i < j && a[i] < x)
			++i;
		if (i < j)
			a[j--] = a[i];
	}
	a[i] = x;
	quicksort(l, i - 1);
	quicksort(i + 1, r);
}
int main(void) {
	int c[100001];
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		a[i].y = i;
		scanf("%d", &a[i].x);
	}
	quicksort(1, n);
	for (int i = 1; i <= n; i++)
		c[a[i].y] = i;
	for (int i = 1; i <= n; i++)
		printf("%d ", c[i]);
	return 0;
}