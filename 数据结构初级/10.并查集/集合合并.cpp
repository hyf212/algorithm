#include<bits/std++.h>

using namespace std;

const int maxn = 100010;

int fa[maxn + 1];//fa 数组记录每个元素由谁代表
int sz[maxn + 1];//sz数组记录每个集合元素个数
int dep[maxn + 1];//dep数组记录每个集合的树深度

void initialize(int n) {
	for (int i = 1; i <= n; i++) {
		fa[i] = i;
		sz[i] = dep[i] = 1;
	}
}
int Findset(int x) {
	if (fa[x] == x)
		return x;
	return Findset(fa[x]);
}
void Union(int x, int y) {
	int fx = Findset(x), fy = Findset(y);
	if (fx == fy) return;
	fa[fx] = fy;
}
//路径压缩
int Findset(int x) {
	if (x == fa[x])
		return x;
	fa[x] = Findset(fa[x]);
	return fa[x];
}
//上述代码简写为
int Findset(int x) {
	return x == fa[x] ? x : (fa[x] = Findset(fa[x]));
}
//启发式合并
void Union(int x, int y) {
	int fx = Findset(x), fy = Findset(y);
	if (fx == fy) return ;
	if (sz[fx] > sz[fy])
		swap(fx, fy);
	fa[fx] = fy;
	sz[fy] += sz[fx];
}
//按深度合并
void Union(int x, int y) {
	int fx = findset(x), fy = findset(y);
	if (fx == fy) return;
	if (dep[fx] > dep[fy])
		swap(fx, fy);
	fa[fx] = fy;
	if (dep[fx] == dep[fy])
		dep[fy]++;
}
int main(void) {
	....
}