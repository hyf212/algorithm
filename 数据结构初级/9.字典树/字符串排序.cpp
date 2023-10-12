#include<bits/stdc++.h>

using namespace std;

int n, m, cnt = 0, nxt[500005][26], a[101];
bool isend[500005];
char str[11];
inline void dfs(int now, int depth) {
	if (isend[now]) {
		for (int i = 0; i < depth; i++)
			printf("%c", a[i] + 'a');
		printf("\n");
	}
	for (int i = 0; i < 26; i++)
		if (nxt[now][i]) {
			a[depth] = i;
			dfs(nxt[now][i], depth + 1);
		}
}
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%s", str);
		int len = strlen(str);
		int now = 0;
		for (int j = 0; j < len; j++) {
			int x = str[j] - 'a';
			if (!nxt[now][x])
				nxt[now][x] = ++cnt;
			now = nxt[now][x];
		}
		isend[now] = true;
	}
	dfs(0, 0);
	return 0;
}