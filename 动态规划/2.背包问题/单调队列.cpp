#include<bits/stdc++.h>

using namespace std;

int n, a[100001], b[100001], front = 1, rear = 0, q[100001];

int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &a[i], &b[i]);
	for (int i = 1; i <= n; i++) {
		while (front <= rear && b[i] >= b[q[rear]])
			--rear;
		while (front <= rear && a[q[front]] < i)
			++front;
		q[++rear] = i;
		printf("%d\n", b[q[front]]);
	}
	return 0;
}