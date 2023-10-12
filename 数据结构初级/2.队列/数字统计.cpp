#include<bits/stdc++.h>

using namespace std;

int n, q[100001], front = 1, rear = 0;
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		for (;front <= rear && q[front] < x - 5; ++front);
		printf("%d ", rear + 1 - front);
		q[++rear] = x;
	}
	return 0;
}