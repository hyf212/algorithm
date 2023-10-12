#include <bits/stdc++.h>

using namespace std;

int n, a[200001], s[200001], top; 

int main() {
	top = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		while (top &&a[s[top]] < a[i])
			if (a[s[top]] < a[i])
				--top, ans++;
		s[++top] = i;
	}
	printf("%lld", ans);
}