#include<bits/stdc++.h>

using namespace std;
struct Info {
	int v;
	int delta;
} heap[200005];
int n, m, len = 0;
inline void up(int k) {
	while (k > 1 && heap[k].v < heap[k / 2].v) {
		swap(heap[k], heap[k / 2]);
		k /= 2;
	}
}
inline void down(int k) {
	while (k + k <= len) {
		int j = k + k;
		if (j + 1 <= len && heap[j + 1].v < heap[j].v)
			j++;
		if (heap[j].v >= heap[k].v)
			break;
		swap(heap[k], heap[j]);
		k = j;
	}
}
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int k, b;
		scanf("%d%d", &k, &b);
		heap[++len].v = b;
		heap[len].delta = k;
		up(len);
	}
	scanf("%d", &m); 
	for (int i = 1; i <= m; i++) {
		printf("%d ", heap[1].v);
		heap[1].v += heap[1].delta;
		down(1);
	}
	return 0;
}

