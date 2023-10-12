#include <bits/stdc++.h>

using namespace std;

const int N = 10000;
vector<int> edge[N + 1];
int n, m, q[N + 1], d[N + 1], f[N + 1];

inline void TopoSort() {
	int front = 1, rear = 0;
	for (int i = 1; i <= n; i++)
		if (!d[i])
			q[++rear] = i;
	while (front <= rear) {
		int x = q[front];
		++front;
		for (auto y : edge[x])
			if (--d[y] == 0)
				q[++rear] = y;
	}
	int ans = 0;
	for (int i = n; i; i--) {
		int x = q[i];
		f[x] = 100;
		for (auto y : edge[x])
			f[x] = max(f[x], f[y] + 1);
	}
	for (int i = 1; i <= n; i++)
		ans += f[i];
	printf("%d\n", ans);
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