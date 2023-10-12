#include <bits/stdc++.h>

using namespace std;

const int N = 100000;
struct Node {
	int y, v;
	Node (int _y, int _v) { y = _y; v = _v;}
};

vector<Node> edge[N + 1], edge2[N + 1];
set< pair<int, int> > q;
int n, m, k, dist[N + 1], f[2][N + 1];

void dijkstra(vector<Node> edge[], int s) {
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
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		int x, y, v;
		scanf("%d%d%d", &x, &y, &v);
		edge[x].push_back(Node(y, v));
		edge2[y].push_back(Node(x, v));
	}
	dijkstra(edge, k);
	memcpy(f[0], dist, sizeof(dist));
	dijkstra(edge2, k);
	memcpy(f[1], dist, sizeof(dist));
	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans = max(ans, f[0][i] + f[1][i]);
	printf("%d\n", ans);
}