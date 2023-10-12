#include<bits/stdc++.h>

using namespace std;

int n, a[100001], s[100001], ans[100001];
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		s[a[i]]++;
	}
	for (int i = 1; i <= 100000; ++i)
		for(int j = 1; j <= s[i]; ++j)
			printf("%d ", i);
	printf("\n");
	for (int i = 1; i <= 100000; i++)
		s[i] += s[i - 1];
	for (int i = n; i; --i) {
		ans[i] = s[a[i]];
		s[a[i]]--;
	}
	for (int i = 1; i <= n; i++)
		printf("%d ", ans[i]);
	return 0;
}