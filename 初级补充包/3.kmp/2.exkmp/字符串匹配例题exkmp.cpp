#include <bits/stdc++.h>

using namespace std;

int t, n, m, z[200011];
char s[100002], p[200011];
void exkmp() {
	n = strlen(s + 1);
	m = strlen(p + 1);
	p[m + 1] = '#';
	for (int i = m + 2, j = 1; j <= n; j++, i++)
		p[i] = s[j];
	int L = 1, R = 0;
	z[1] = 0;
	for (int i = 2; i <= m + n + 1; i++) {
		if (i > R)
			z[i] = 0;
		else {
			int k = i - L + 1;
			z[i] = min(z[k], R - i + 1);
		}
		while (i + z[i] <= n + m + 1 && p[z[i] + 1] == p[z[i] + i])
			++z[i];
		if (i + z[i] - 1 > R)
			L = i, R = i + z[i] - 1;
	}
	int ans = 0;
	for (int i = m + 2; i <= m + n + 1; i++)
		if (z[i] == m)
			++ans;
	if (!ans)
		printf("-1\n-1\n");
	else {
		printf("%d\n", ans);
		for (int i = m + 2; i <= n + m + 1; i++)
			if (z[i] == m)
				printf("%d ", i - m - 1);
		printf("\n");
	}
}
int main(void) {
	scanf("%d", &t);
	while(t--) {
		scanf("%s%s", s + 1, p + 1);
		exkmp();
	}
	return 0;
}