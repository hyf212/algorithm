#include <bits/stdc++.h>

using namespace std;

int n, m;
bool b[200001];
vector<int> edge[200001];

void dfs(int x) {
	b[x] = true;
	for (auto y : edge[x])
		if (!b[y])
			dfs(y);
}
int main(void) {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	memset(b, false, sizeof(b));
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		if (!b[i]) {
			dfs(i);
			++cnt;
		}
	printf("%d", cnt);
	return 0;
}