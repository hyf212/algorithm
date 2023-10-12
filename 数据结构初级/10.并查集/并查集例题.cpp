/*#include<bits/stdc++.h>

using namespace std;

int n, m, fa[100001];
char str[11];
int Findset(int x) {
	if (x == fa[x])
		return x;
	fa[x] = Findset(fa[x]);
	return fa[x];
}
int main(void) {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	for (int i = 1; i <= m; i++) {
		int x, y;
		scanf("%s%d%d", str, &x, &y);
		if (str[0] == 'M') {
			int fx = Findset(x), fy = Findset(y);
			if (fx == fy)
				continue;
			fa[fx] = fy;
		} else {
			int fx = Findset(x), fy = Findset(y);
			if (fx == fy)
				printf("1\n");
			else
				printf("0\n");
		}
	}
	return 0;
}*/
#include<bits/stdc++.h>

using namespace std;

int n, m, fa[100001], sz[100001];
char str[11];
int Findset(int x) {
	if (x == fa[x])
		return x;
	fa[x] = Findset(fa[x]);
	return fa[x];
}
int main(void) {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		fa[i] = i, sz[i] = 1;
	for (int i = 1; i <= m; i++) {
		int x, y;
		scanf("%s%d%d", str, &x, &y);
		if (str[0] == 'M') {
			int fx = Findset(x), fy = Findset(y);
			if (fx == fy)
				continue;
			if (sz[fx] > sz[fy])
				swap(fx, fy);
			fa[fx] = fy;
			sz[fy] += sz[fx];
		} else {
			int fx = Findset(x), fy = Findset(y);
			if (fx == fy)
				printf("1\n");
			else
				printf("0\n");
		}
	}
	return 0;
}