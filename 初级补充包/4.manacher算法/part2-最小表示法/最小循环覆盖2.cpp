#include <bits/stdc++.h>

using namespace std;

int n, nxt[200002];
char s[200002];

inline void getmin(char s[]) {
	n = strlen(s + 1);
	int j = 0;
	nxt[1] = 0;
	for (int i = 2; i <= n; i++) {
		while (j && s[i] != s[j + 1])
			j = nxt[j];
		if (s[i] == s[j + 1])
			++j;
		nxt[i] = j;
	}
	n -= nxt[n];
	for (int l = 1; l <= n; l++)
		s[l + n] = s[l];
	int i = 1;
	j = 2;
	while (j <= n) {
		int k = 0;
		while (k < n && s[i + k] == s[j + k])
			++k;
		if (s[i + k] > s[j + k])
			i += k + 1;
		else
			j += k + 1;
		if (i == j)
			++j;
		if (i > j)
			swap(i, j);
	}
	for (int l = i; l <= i + n - 1; l++)
		printf("%c", s[l]);
}
int main(void) {
	scanf("%s", s + 1);
	getmin(s);
	return 0;
}