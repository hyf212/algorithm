#include<bits/stdc++.h>

using namespace std;

int n, s[3000001], a[3000001], ans[3000001], top = 0;
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) {
		while (top && a[i] > a[s[top]]) {
			ans[s[top]] = i;
			--top;
		}
		s[++top] = i;
	}
	for (int i = 1; i <= top; i++)
		ans[s[i]] = 0;
	for (int i = 1; i <= n; i++)
		printf("%d ", ans[i]);
	return 0;
}