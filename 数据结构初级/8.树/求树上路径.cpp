/*#include<bits/stdc++.h>

using namespace std;

int n, pre[100001], c[100001], l = 0;
vector<int> edges[100001];

inline void dfs(int x) {
	for (auto y : edges[x])
		if (y != pre[x]) {
			pre[y] = x;
			dfs(y);
		}
}
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		edges[x].push_back(y);
		edges[y].push_back(x);
	}
	int u, v;
	scanf("%d%d", &u, &v);
	pre[u] = -1;
	dfs(u);
	for (int i = v; i != u; i = pre[i])
		c[++l] = i;
	c[++l] = u;
	for (int i = l; i; i--)
		printf("%d ", c[i]);
	return 0;
}*/
#include<bits/stdc++.h>

using namespace std;

int n, pre[100001], c[100001], q[100001], front = 1, rear = 0, l = 0;
vector<int> edges[100001];

inline void bfs(int u) {
	q[++rear] = u;
	while (front <= rear) {
		int x = q[front];
		++front;
		for (auto y : edges[x])
			if (y != pre[x]) {
				pre[y] = x;
				q[++rear] = y;
			}
	}
}
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		edges[x].push_back(y);
		edges[y].push_back(x);
	}
	int u, v;
	scanf("%d%d", &u, &v);
	pre[u] = -1;
	bfs(u);
	for (int i = v; i != u; i = pre[i])
		c[++l] = i;
	c[++l] = u;
	for (int i = l; i; i--)
		printf("%d ", c[i]);
	return 0;
}