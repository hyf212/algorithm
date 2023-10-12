#include<bits/stdc++.h>

using namespace std;

int x, k, q[200005], front = 1, rear = 0;
int main(void) {
	scanf("%d%d", &x, &k);
	q[++rear] = x;
	for (int i = 1; i <= k; i++) {
		q[++rear] = 2 * q[front];
		q[++rear] = 2 * q[front] + 1;
		printf("%d\n", q[front++]);
	}
	return 0;
}