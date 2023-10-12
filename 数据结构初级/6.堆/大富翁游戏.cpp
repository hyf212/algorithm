#include<bits/stdc++.h>

using namespace std;
struct Info {
	int v;
	int pos;
} heap1[100005], heap2[100005];
int n, m, s1[100005], s2[100005], len1, len2;
inline void up1(int k) {
	while (k > 1 && heap1[k].v < heap1[k / 2].v) {
		swap(heap1[k], heap1[k / 2]);
		s1[heap1[k].pos] = k;
		s1[heap1[k / 2].pos] = k / 2;
		k /= 2;
	}
}
inline void up2(int k) {
	while (k > 1 && heap2[k].v > heap2[k / 2].v) {
		swap(heap2[k], heap2[k / 2]);
		s2[heap2[k].pos] = k;
		s2[heap2[k / 2].pos] = k / 2;
		k /= 2;
	}
}
inline void down1(int k) {
	while (k + k <= len1) {
		int j = k + k;
		if (j + 1 <= len1 && heap1[j].v > heap1[j + 1].v)
			j++;
		if (heap1[k].v <= heap1[j].v)
			break;
		swap(heap1[j], heap1[k]);
		s1[heap1[j].pos] = j;
		s1[heap1[k].pos] = k;
		k = j;
		
	}
}
inline void down2(int k) {
	while (k + k <= len2) {
		int j = k + k;
		if (j + 1 <= len2 && heap2[j].v < heap2[j + 1].v)
			j++;
		if (heap2[k].v >= heap2[j].v)
			break;
		swap(heap2[j], heap2[k]);
		s2[heap2[j].pos] = j;
		s2[heap2[k].pos] = k;
		k = j;
		
	}
}
int main(void) {
	scanf("%d%d", &n, &m);
	len1 = len2 = 0;
	for (int i = 1; i <= n; i++) {
		heap1[++len1].v = 100;
		heap1[len1].pos = i;
		s1[i] = len1;
		up1(len1);
		heap2[++len2].v = 100;
		heap2[len2].pos = i;
		s2[i] = len2;
		up2(len2);
	}
	for (int i = 1; i <= m; i++) {
		int x;
		scanf("%d", &x);
		if (x == 1) {
			int y, z;
			scanf("%d%d", &y, &z);
			heap1[s1[y]].v += z;
			up1(s1[y]);
			down1(s1[y]);
			heap2[s2[y]].v += z;
			up2(s2[y]);
			down2(s2[y]);
		} else {
			printf("%d %d\n", heap2[1].v, heap1[1].v);
		}
	}
	return 0;
}