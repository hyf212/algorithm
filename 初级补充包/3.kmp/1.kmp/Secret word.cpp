/*#include <bits/stdc++.h>

using namespace std;

int m;
int nxt[100001], f[100001];
char s[100002], p[100002];

void kmp() {
	m = strlen(s + 1);
	for (int i = m, j = 1; i; i--, j++)
		p[j] = s[i];
	int j = 0;
	nxt[1] = 0;
	for (int i = 2; i <= m; i++) {
		while (j && s[j + 1] != s[i])
			j = nxt[j];
		if (s[j + 1] == s[i])
			++j;
		nxt[i] = j;
	}
	j = 0;
	for (int i = 1; i <= m; i++) {
		while ((j == m) || (j > 0) && s[j + 1] != p[i])
			j = nxt[j];
		if (s[j + 1] == p[i])
			++j;
		f[i] = j;
	}
	int ans = 0;
	for (int i = 1; i <= m; i++)
		ans = max(ans, f[i]);
	for (int i = ans; i; i--)
		printf("%c", s[i]);
}
int main(void) {
	scanf("%s", s + 1);
	kmp();
	return 0;
}*/
#include <bits/stdc++.h>

using namespace std;

int m;
int nxt[200011];
char p[200011];

void kmp() {
	m = strlen(p + 1);
	p[m + 1] = '#';
	for (int i = m + 2, j = m; j; j--, i++)
		p[i] = p[j];
	int j = 0;
	nxt[1] = 0;
	for (int i = 2;i <= m + m + 1; i++) {
		while (j && p[i] != p[j + 1])
			j = nxt[j];
		if (p[i] == p[j + 1])
			++j;
		nxt[i] = j;
	}
	int x = 0;
	for (int i = m + 2; i <= m + m + 1; i++)
		x = max(x, nxt[i]);
	for (int i = x; i >= 1; i--)
		printf("%c", p[i]);
	
}
int main(void) {
	scanf("%s", p + 1);
	kmp();
	return 0;
}