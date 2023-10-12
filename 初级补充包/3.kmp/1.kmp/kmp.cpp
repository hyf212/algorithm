#include <bits/stdc++.h>

using namespace std;

int n, m;
int nxt[M + 1], f[N + 1];
char s[N + 2], p[N + 2];

void kmp() {
	n = strlen(s + 1);
	m = strlen(p + 1);
	int j = 0;
	nxt[1] = 0;
	for (int i = 2; i <= m; i++) {
		while (j && p[j + 1] != p[i])
			j = nxt[j];
		if (p[j + 1] == s[i])
			++j;
		nxt[i] = j;
	}
	j = 0;
	for (int i = 1; i <= n; i++) {
		while ((j == m) || (j > 0) && p[j + 1] != s[i])
			j = nxt[j];
		if (p[j + 1] == s[i])
			++j;
		f[i] = j;
	}
}
int main(void) {
	return 0;
}