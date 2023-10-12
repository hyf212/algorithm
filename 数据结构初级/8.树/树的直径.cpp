/*#include<bits/stdc++.h>

using namespace std;

int n, pre[100001], dict[100001];
vector<int> edges[100001];

inline void dfs(int x) {
	for (auto y : edges[x])
		if (y != pre[x]) {
			pre[y] = x;
			dict[y] = dict[x] + 1;
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
	memset(dict, 0, sizeof(dict));
	memset(pre, 0, sizeof(pre));
	pre[1] = -1;
	dfs(1);
	int idx = 0, v = 0;
	for (int i = 1; i <= n; i++)
		if (dict[i] > v)
			v = dict[i], idx = i;
	memset(dict, 0, sizeof(dict));
	memset(pre, 0, sizeof(pre));
	pre[idx] = -1;
	dfs(idx);
	int ant = 0;
	for (int i = 1; i <= n; i++)
		ant = max(ant, dict[i]);
	printf("%d", ant);
	return 0;
}*/
#include<bits/stdc++.h>

using namespace std;

int n, q[100005], pre[100005], dict[100005], front = 1, rear = 0;
vector<int> edges[100005];
inline void bfs(int u) {
	q[++rear] = u;
	while (front <= rear) {
		int x = q[front];
		++front;
		for (auto y : edges[x])
			if (y != pre[x]) {
				pre[y] = x;
				q[++rear] = y;
				dict[y] = dict[x] + 1;
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
	memset(pre, 0, sizeof(pre));
	memset(dict, 0, sizeof(dict));
	pre[1] = -1;
	bfs(1);
	int idx = 0, v = 0;
	for (int i = 1; i <= n; i++)
		if (dict[i] > v)
			v = dict[i], idx = i;
	memset(pre, 0, sizeof(pre));
	memset(dict, 0, sizeof(dict));
	pre[idx] = -1;
	bfs(idx);
	v = 0;
	for (int i = 1; i <= n; i++)
		v = max(v, dict[i]);
	printf("%d", v);
	return 0;
}