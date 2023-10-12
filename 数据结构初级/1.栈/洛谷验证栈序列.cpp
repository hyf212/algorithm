#include<bits/stdc++.h>

using namespace std;

int q;
int main(void) {
	scanf("%d", &q);
	int ans = 1;
	while (q--) {
		int n, s[100001] = {0}, a[100001], b[100001],top = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		for (int i = 1; i <= n; i++)
			scanf("%d", &b[i]);
		for (int i = 1; i <= n; i++) {
			s[++top] = a[i];
			while (s[top] == b[ans] && s[top] && b[ans]) {
				--top;
				ans++;
			}
		}
		if (top != 0)
			printf("No\n");
		else
			printf("Yes\n");
		top = 0;
		ans = 1;
	}
	return 0;
}