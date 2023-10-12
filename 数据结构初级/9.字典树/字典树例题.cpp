#include<bits/stdc++.h>

using namespace std;

int n, m, cnt = 0, nxt[500001][26];
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
		}
		isend[now] = true;
	}
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		scanf("%s", str);
		int len = strlen(str);
		int now = 0;
		bool ok = true;
		for (int j = 0; j < len && ok; j++) {
			int x = str[j] - 'a';
			if (!nxt[now][x])
				ok = false;
			else
				now = nxt[now][x];
		}
		if (ok)
			if (!isend[now])
				ok = false;
		printf("%d\n", ok);
	}
	return 0;
}