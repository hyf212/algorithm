#include<bits/stdc++.h>

using namespace std;

int n, m, a[100001];
inline void quicksort(int l, int r) {
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
	quicksort(l, i - 1);
	quicksort(i + 1, r);
}

int main(void) {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	quicksort(1, n);
	printf("%d\n", a[m]);
}