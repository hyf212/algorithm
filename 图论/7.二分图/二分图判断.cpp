#include <bits/stdc++.h>

using namespace std;

const int N = 1000;
vector<int> edge[N + 1];
int n, m, c[N + 1];

bool dfs(int x) {
	for (auto y : edge[x])
		if (!c[y]) {
			c[y] = 3 - c[x];
			if (!dfs(y))
				return false;
		} else
			if (c[x] == c[y])
				return false;
	return true;
}

bool check() {
	for (int i = 1; i <= n; i++)
		if (!c[i]) {
			c[i] = 1;
			if (!dfs(i))
				return false;
		}
	return true;
}

int main () {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	if (check())
		printf("Yes\n");
	else
		printf("No\n");
}