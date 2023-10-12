#include <bits/stdc++.h>

using namespace std;

const int N = 1000001;
int n, k, c, a[N], q[N];
int main() {
	scanf("%d%d%d", &n, &k, &c);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	int front = 1, rear = 0, ans = 0;
	for (int i = 1; i <= n; i++) {
		while (front <= rear && a[q[rear]] <= a[i])
			--rear;
		q[++rear] = i;
		if (i - c + 1 >= 1) {
			if (a[q[front]] <= k)
				++ans;
			if (q[front] == i - c + 1)
				++front;
		}
	}
	printf("%d", ans);
}