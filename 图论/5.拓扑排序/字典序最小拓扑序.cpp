#include <bits/stdc++.h>

using namespace std;

const int N = 10000;
vector<int> edge[N + 1];
priority_queue<int, vector<int>, greater<int>> q;
int n, m, d[N + 1], l[N + 1], cnt;

inline void TopoSort() {
	for (int i = 1; i <= n; i++)
		if (!d[i])
			q.push(i);
	while (!q.empty()) {
		int x = q.top();
		l[++cnt] = x;
		q.pop();
		for (auto y : edge[x])
			if (--d[y] == 0)
				q.push(y);
	}
	for (int i = 1; i <= cnt; i++)
		printf("%d ", l[i]);
	printf("\n");
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		edge[x].push_back(y);
		d[y]++;
	}
	TopoSort();
}
