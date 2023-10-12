/*#include<bits/stdc++.h>

using namespace std;
int n, heap[100005], len = 0;
inline void up(int k) {
	while (k > 1 && heap[k] < heap[k / 2]) {
		swap(heap[k], heap[k / 2]);
		k /= 2;
	}
}
inline void down(int k) {
	while (k + k <= len) {
		int j = k + k;
		if (j + 1 <= len && heap[j + 1] < heap[j])
			j++;
		if (heap[j] >= heap[k])
			break;
		swap(heap[k], heap[j]);
		k = j;
	}
}
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		heap[++len] = x;
		up(len);
	}
	for (int i = 1; i <= n; i++) {
		printf("%d ", heap[1]);
		swap(heap[1], heap[len]);
		--len;
		down(1);
	}
	return 0;
}*/
#include<bits/stdc++.h>
using namespace std;
priority_queue<int, vector<int>, greater<int>> q;
int n;
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		q.push(x);
	}
	for (int i = 1; i <= n; i++) {
		printf("%d ", q.top());
		q.pop();
	}
	return 0;
}