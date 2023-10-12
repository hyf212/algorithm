/*#include<bits/stdc++.h>

using namespace std;

int n, m, fa[100001], size[100001], ans[100001];
int Findset(int x) {
	if (x == fa[x])
		return x;
	fa[x] = Findset(fa[x]);
	return fa[x];
}
int main(void) {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		fa[i] = i, size[i] = 1;
	for (int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		int fx = Findset(x), fy = Findset(y);
		if (fx == fy)
			continue;
		if (size[fx] > size[fy])
			swap(fx, fy);
		fa[fx] = fy;
		size[fy] += size[fx];
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		if (fa[i] == i)
			cnt++;
	printf("%d", cnt - 1);
	return 0;
}*/


#include <bits/stdc++.h>

using namespace std;

const int N = 100000;
int n, m, fa[N + 1], sz[N + 1];

int Findset(int x) {
	if (x == fa[x])
		return fa[x];
	fa[x] = Findset(fa[x]);
	return fa[x]; 
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		fa[i] = i, sz[i] = 1;
	for (int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		int fx = Findset(x), fy = Findset(y);
		if (fx == fy)
			continue;
		if (sz[fx] > sz[fy])
			swap(fx, fy);
		fa[fx] = fy;
		sz[fy] += sz[fx]; 
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		if (fa[i] == i)
			cnt++;
	printf("%d", cnt - 1);
} 