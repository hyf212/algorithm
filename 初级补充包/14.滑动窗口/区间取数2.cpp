#include <bits/stdc++.h>

using namespace std;

const int N = 1000001;
int n, k;
long long a[N], q[N];
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		a[i] += a[i - 1];
	}
//	int front  = 1, rear = 0, ans = 0;
//	for (int i = 1; i <= n; i++) {
//		while (front <= rear && a[i] - a[q[front] - 1] > k)
//			++front;
//		q[++rear] = i;
//		ans = max(ans, rear - front + 1);
//	
	int x = 1, ans = 0;
	for (int i = 1; i <= n; i++) {
		while (x <= n && a[x] - a[i - 1] <= k)
			x++;
		ans = max(ans, x - i);
	}
	printf("%d\n", ans);
}