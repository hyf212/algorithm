#include <bits/stdc++.h>

using namespace std;

int m;
int nxt[100001];
char p[100002];

void kmp() {
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
	printf("%d ", m - nxt[m]);
}
int main(void) {
	scanf("%s", p + 1);
	kmp();
	return 0;
}