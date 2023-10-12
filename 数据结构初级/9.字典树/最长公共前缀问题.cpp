#include<bits/stdc++.h>

using namespace std;

int n, m, cnt = 0, nxt[500001][26], father[500001][30], idx[500001], d[500001];
char str[10011];

int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%s", str);
		int len = strlen(str);
		int now = 0;
		for (int j = 0; j < len; j++) {
			int x = str[j] - 'a';
			if (!nxt[now][x]) {
				nxt[now][x] = ++cnt;
				father[cnt][0] = now;
				d[cnt] = d[now] + 1;
			}
			now = nxt[now][x];
		}
		idx[i] = now;
	}
	for (int i = 1; i <= 20; ++i)
		for (int j = 1; j <= cnt; j++)
			if (father[j][i - 1])
				father[j][i] = father[father[j][i - 1]][i - 1];
	scanf("%d", &m);
	for (int i = 1; i <= m; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		x = idx[x], y = idx[y];
		if (d[x] < d[y])
			swap(x, y);
		int z = d[x] - d[y];
		for (int j = 0; j < 20 && z; j++, z /= 2)
			if (z & 1)
				x = father[x][j];
		if (x == y) {
			printf("%d\n", d[x]);
			continue;
		}
		for (int j = 20; j >= 0; --j) {
			if (father[x][j] != father[y][j])
				x = father[x][j], y = father[y][j];
		}
		printf("%d\n", d[father[x][0]]);
	}
	return 0;
}