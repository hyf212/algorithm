#include<bits/stdc++.h>

using namespace std;
int n, s[200001], a[200001], l[200001], r[200001],top = 0;
long long sum= 0;
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) {
		while (top && a[i] <= a[s[top]])
			--top;
		if (top)
			l[i] = s[top];
		else
			l[i] = 0;
		s[++top] = i;
	}
	top = 0;
	for (int i = n; i > 0; i--) {
		while (top && a[i] <= a[s[top]])
			--top;
		if (top)
			r[i] = s[top] - 1;
		else
			r[i] = n;
		s[++top] = i;
	}
	for (int i = 1; i <= n; i++)
		sum = max(sum, 1LL * a[i] * (r[i] - l[i]));
	printf("%lld", sum);
	return 0;
}