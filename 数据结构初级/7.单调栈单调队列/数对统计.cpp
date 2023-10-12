#include<bits/stdc++.h>

using namespace std;
int n, s[200001], a[200001], top = 0, ans = 0;
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) {
		while (top && a[i] > s[top])
			--top, ans++;
		if (top)
			ans++;
		s[++top] = a[i];
	}
	printf("%d", ans);
	return 0;
}