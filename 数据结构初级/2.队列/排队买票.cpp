#include<bits/stdc++.h>

using namespace std;

int n, q[1000001], a[1001], ans[1001], front = 1, rear = 0;
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		q[++rear] = i;
	}
	while (front <= rear) {
		if (a[q[front]] - 1)
			q[++rear] = q[front], a[q[front++]]--;
		else
			ans[q[front]] = front, front++;
		}
	for (int i = 1; i <= n; i++)
		printf("%d ", ans[i]);
	return 0;
}