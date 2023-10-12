#include<bits/stdc++.h>
using namespace std;
int n;
inline void quicksort(int a[], int l, int r) {
	if(l >= r)
		return;
	swap(a[l], a[l + rand()%(r - l + 1)]);
	int x = a[l], i = l, j = r;
	while (i < j) {
		while (i < j && a[j] > x)
			--j;
		if (i < j)
			a[i++] = a[j];
		while (i < j && a[i] < x)
			++i;
		if (i < j)
			a[j--] = a[i];
	}
	a[i] = x;
	quicksort(a, l, i - 1);
	quicksort(a, i + 1, r);
}
int main(void) {
	int a[100001];
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	quicksort(a, 1, n);
	for (int i = 1; i <= n; i++) {
		printf("%d ", a[i]);
	}
	return 0;
}