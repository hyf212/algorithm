#include<bits/stdc++.h>

using namespace std;

int n, a[200001], s[200001], top = 0;
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	int ans = 0, cnt = 1;
	for (int i = 1; i <= n; i++) {
		if (top && a[i] > s[top]) {
			ans += 1;
			--top;
		} else
			if (a[i] == s[top]) {
			cnt++;
		}
		if (top) {
			ans += cnt;
		}
		if (s[top] != a[i] || !top) {
			s[++top] = a[i];
			ans += cnt * (cnt - 1) / 2;
		}
	}
	printf("%d", ans);
	return 0;
}