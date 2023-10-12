#include<bits/stdc++.h>

using namespace std;

int n, m, s[200001], q[200001], a[200001], front = 1, rear = 0, l, r;

int main(void) {
	scanf("%d%d%d", &n, &l, &r);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)
		s[i] = s[i - 1] + a[i];
	int x = l, ans = -1 << 30;
	for (int i = 1; i + l - 1 <= n; i++) {
		while (x <= i + r - 1 & & x <= n) {
			while (front <= rear && s[q[rear]] <= s[x])
				--rear;
			q[++rear] = x;
			++x;
		}
		while (q[front] < i + l - 1)
			++front;
		ans = max(ans, s[q[front]] - s[i - 1]);
	}
	printf("%d", ans);
	return 0;
}