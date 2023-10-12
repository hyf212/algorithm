/*#include <bits/stdc++.h>

using namespace std;

int t, n, m;
int nxt[100001], f[100001];
char s[100002], p[100002];

void kmp() {
	n = strlen(s + 1);
	m = strlen(p + 1);
	int j = 0;
	nxt[1] = 0;
	for (int i = 2; i <= m; i++) {
		while (j && p[j + 1] != p[i])
			j = nxt[j];
		if (p[j + 1] == p[i])
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
	int ans = 0;
	for (int i = 1; i <= n; i++)
		if (f[i] == m)
			ans++;
	if (!ans)
		printf("-1\n-1\n");
	else {
		printf("%d\n", ans);
		for (int i = 1; i <= n; i++)
			if (f[i] == m)
				printf("%d ", i - m + 1);
		printf("\n");
	}
}
int main(void) {
	scanf("%d", &t);
	while (t--) {
		scanf("%s%s", s + 1, p + 1);
		kmp();
	}
	return 0;
}*/
#include <bits/stdc++.h>

using namespace std;

int t, n, m;
int nxt[200011];
char s[100002], p[200011];

void kmp() {
	n = strlen(s + 1);
	m = strlen(p + 1);
	p[m + 1] = '#';
	for (int i = 1, j = m + 2; i <= n; i++, j++)
		p[j] = s[i];
	int j = 0;
	nxt[1] = 0;
	for (int i = 2; i <= m + n + 1; i++) {
		while (j && p[j + 1] != p[i])
			j = nxt[j];
		if (p[j + 1] == p[i])
			++j;
		nxt[i] = j;
	}
	int ans = 0;
	for (int i = m + 2; i <= n + m + 1; i++)
		if (nxt[i] == m)
			ans++;
	if (!ans)
		printf("-1\n-1\n");
	else {
		printf("%d\n", ans);
		for (int i = m + 2; i <= n + m + 1; i++)
			if (nxt[i] == m)
				printf("%d ", i - 2 * m);
		printf("\n");
	}
}
int main(void) {
	scanf("%d", &t);
	while (t--) {
		scanf("%s%s", s + 1, p + 1);
		kmp();
	}
	return 0;
}