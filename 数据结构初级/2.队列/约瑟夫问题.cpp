#include<bits/stdc++.h>

using namespace std;

int n, m, q[100001], front = 1, rear = 0;
int main(void) {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		q[++rear] = i;
	int cnt = 0;
	while (front <= rear) {
		++cnt;
		if (cnt == m) {
			cnt = 0;
			printf("%d ", q[front]);
		} else {
			q[++rear] = q[front];
		}
		++front;
	}
	return 0;
}