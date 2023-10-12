#include <bits/stdc++.h>

using namespace std;

const int N = 100001;
int n, m, t, nxt[2 * N + 1];
char s[N], p[2 * N + 1];

void kmp() {
	n = strlen(s);
	m = strlen(p);
	p[m] = '#';
	for (int i = m + 1, j = 0; j < n; j++, i++)
		p[i] = s[j];
	int j = -1;
	nxt[0] = -1;
	for (int i = 1; i <= m + n; i++) {
		while (j != -1 && p[i] != p[j + 1])
			j = nxt[j];
		if (p[j + 1] == p[i])
			++j;
		nxt[i] = j;
	}
	int ans = 0;
	for (int i = m + 1; i <= n + m; i++)
		if (nxt[i] == m - 1)
			ans++;
	if (!ans)
		printf("-1\n-1\n");
	else {
		printf("%d\n", ans);
		for (int i = m + 1; i <= n + m; i++)
			if (nxt[i] == m - 1)
				printf("%d ", i - 2 * m + 1);
		printf("\n");
	}
}
int main() {
	scanf("%d", &t);
	while (t--) {
		cin >> s >> p;
		kmp();
	}
}