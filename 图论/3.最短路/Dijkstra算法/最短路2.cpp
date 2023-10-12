#include <bits/stdc++.h>

using namespace std;

struct Node {
	int y, v;
	Node(int _y, int _v) {
	 y = _y;
	  v = _v;
	  }
};
set< pair<int, int> > q;
vector<Node> edge[100001];
int n, m, k, dist[100001];
bool b[100001];
inline void Dijkstra(int s, int t) {
	memset(dist, 127, sizeof(dist));
	memset(b, false, sizeof(b));
	dist[s] = 0;
	q.clear();
	for (int i = 1; i <= n; i++)
		q.insert(make_pair(dist[i], i));
	while (!q.empty()) {
		int x = q.begin()->second;
		if (x == t || dist[x] > 1 << 30)
			break;
		b[x] = true;
		q.erase(q.begin());
		for (auto i : edge[x])
			if (!b[i.y] && dist[x] + i.v < dist[i.y]) {
				q.erase(make_pair(dist[i.y], i.y));
				dist[i.y] = dist[x] + i.v;
				q.insert(make_pair(dist[i.y], i.y));
			}
	}
	if (dist[t] < 1 << 30)
		printf("%d\n", dist[t]);
	else
		printf("-1\n");
	
}
int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		int x, y, v;
		scanf("%d%d%d", &x, &y, &v);
		edge[x].push_back(Node(y, v));
	}
	while (k--) {
		int s, t;
		scanf("%d%d", &s, &t);
		Dijkstra(s, t);
	}
}