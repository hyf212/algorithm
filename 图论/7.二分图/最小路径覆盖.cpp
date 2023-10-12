#include <bits/stdc++.h>

using namespace std;

vector<int> edge[1001];
int n, m, v[1001];
bool b[1001];
bool find(int x) {
	b[x] = true;
	for (auto y : edge[x])
		if (!v[y] || (!b[v[y]] && find(v[y]))) {
			v[y] = x;
			return true;
		}
	return false;
}
int match() {
	int ans = 0;
	memset(v, 0, sizeof(v));
	for (int i = 1; i <= n; i++) {
		memset(b, false, sizeof(b));
		if (find(i))
			++ans;
	}
	return ans;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		edge[x].push_back(y);
	}
	printf("%d", n - match());
}