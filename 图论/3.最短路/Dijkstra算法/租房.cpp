#include <bits/stdc++.h>

using namespace std;

const int N = 5000;
struct Node {
	int y, v;
	Node (int _y, int _v) { y = _y; v = _v;}
};

vector<Node> edge[N + 1];
set< pair<int, int> > q;
int n, m, a, b, c, dist[N + 1], f[3][N + 1];

void dijkstra(int s) {
	memset(dist, 127, sizeof(dist));
	dist[s] = 0;
	q.clear();
	for (int i = 1; i <= n; i++)
		q.insert(make_pair(dist[i], i));
	while(!q.empty()) {
		int x = q.begin()->second;
		q.erase(q.begin());
		for (auto i : edge[x])
			if (dist[x] < 1 << 30)
				if (dist[x] + i.v < dist[i.y]) {
					q.erase({dist[i.y], i.y});
					dist[i.y] = dist[x] + i.v;
					q.insert({dist[i.y], i.y});
				}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int x, y, v;
		scanf("%d%d%d", &x, &y, &v);
		edge[x].push_back(Node(y, v));
		edge[y].push_back(Node(x, v));
	}
	scanf("%d%d%d", &a, &b, &c);
	dijkstra(a);
	memcpy(f[0], dist, sizeof(dist));
	dijkstra(b);
	memcpy(f[1], dist, sizeof(dist));
	dijkstra(c);
	memcpy(f[2], dist, sizeof(dist));
	int ans = 1 << 30;
	for (int i = 1; i <= n; i++)
		ans = min(ans, f[0][i] + f[1][i] + f[2][i]);
	printf("%d\n", ans);
}