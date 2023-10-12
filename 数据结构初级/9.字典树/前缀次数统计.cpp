#include<bits/stdc++.h>

using namespace std;

int n, m, nxt[500001][26], cnt = 0, tot[500001];
bool isend[500001];
char str[11];
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
			++tot[now];
		}
		isend[now] = true;
	}
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		scanf("%s", str);
		int len = strlen(str);
		int now = 0, ans = 0;
		int ok = true;
		for (int j = 0; j < len && ok; j++) {
			int x = str[j] - 'a';
			if (!nxt[now][x])
				ok = false;
			else
				now = nxt[now][x];
		}
		if (!ok)
			printf("0\n");
		else 
			printf("%d\n", tot[now]);
	}
	return 0;
}