#include <bits/stdc++.h>

using namespace std;

int n, p[2 * N + 2];
char s[N + 2], t[2 * N + 3];

void manacher() {
	n = strlen(s + 1);
	int m = 0;
	t[++m] = '$';
	for (int i = 1; i <= n; i++)
		t[++m] = s[i], t[++m] = '$';
	int M = 0, R = 0;
	for (int i = 1; i <= m; i++) {
		if (i > R)
			p[i] = 1;
		else
			p[i] = min(p[2 * M - i], R - i + 1);
		while (i - p[i] > 0 && i + p[i] <= m &&t[i - p[i]] == t[i + p[i]])
			++p[i];
		if (i + p[i] - 1 > R)
			M = i, R = i + p[i] - 1;
	}
	int ans = 0;
	for (int i = 1; i <= m; i++)
		ans = max(ans, p[i]);
	printf("%d\n", ans - 1);
}
int main(void) {
	manacher();
	return 0;
}