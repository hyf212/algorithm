/*#include <bits/stdc++.h>

using namespace std;

const int N = 100000;
int n, m, nxt[3 * N + 3];
char s[N + 2], p[3 * N + 3];

void kmp() {
	n = strlen(s + 1);
	m = strlen(p + 1);
	p[m + 1] = '#';
	for (int i = 1, j = m + 2; i <= n; j++, i++)
		p[j] = s[i], p[j + n] = s[i];
	int j = 0;
	nxt[1] = 0;
	for (int i = 2; i <= m + n * 2 + 1; i++) {
		while (j && p[i] != p[j + 1])
			j = nxt[j];
		if (p[j + 1] == p[i])
			++j;
		nxt[i] = j;
	}
	bool ok = false;
	for (int i = m + 2; i <= 2 * n + m + 1 && !ok; i++)
		if (nxt[i] == m)
			ok = true;
	if (ok)
		printf("Yes");
	else
		printf("No");
}
int main(void) {
	scanf("%s%s", s + 1, p + 1);
	kmp();
	return 0;
}*/
#include <bits/stdc++.h>

using namespace std;

char s[200002], t[200002];

string getmin(char s[]) {
	int n = strlen(s + 1);
	for (int l = 1; l <= n; l++)
		s[l + n] = s[l];
	int i = 1, j = 2;
	while (j <= n) {
		int k = 0;
		while (k < n && s[k + i] == s[k + j])
			++k;
		if (s[k + i] > s[k + j])
			i += k + 1;
		else
			j += k + 1;
		if (i == j)
			j++;
		if (i > j)
			swap(i, j);
	}
	string res = "";
	for (int l = i; l <= i + n - 1; l++)
		res += s[l];
	return res;
}

int main(void) {
	scanf("%s%s", s + 1, t + 1);
	if (getmin(s) == getmin(t))
		printf("Yes");
	else
		printf("No");
	return 0;
}