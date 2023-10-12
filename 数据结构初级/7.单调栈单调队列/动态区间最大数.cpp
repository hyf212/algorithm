#include<bits/stdc++.h>

using namespace std;
int n, m, q[200001], a[200001], front = 1, rear = 0;
int main(void) {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++) {
		q[++rear] = i;
		if (q[front] < i - m + 1)
			++front;
		if (i >= m)
			printf("%d ", a[q[front]]);
	}
	return 0;
	
}