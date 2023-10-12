#include <bits/stdc++.h>

using namespace std;

int n, c[256];
char s[100011];
int main() {
	scanf("%d%s", &n, s + 1);
	memset(c, 0, sizeof(c));
	int tot = 0;
	for (int i = 1; i <= n; i++)
		if (++c[s[i]] == 1)
			++tot;
	memset(c, 0, sizeof(c));
	int d = 0, ans = 1 << 30, x = 1;
	for (int i = 1; i <= n; i++) {
		while (x <= n && d < tot) {
			if (++c[s[x]] == 1)
				++d;
			++x;			
		}
		if (d == tot)
			ans = min(ans, x - i);
		if (--c[s[i]] == 0)
			--d;
	}
	printf("%d\n", ans);
}