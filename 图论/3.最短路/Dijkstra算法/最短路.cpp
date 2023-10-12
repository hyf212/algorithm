#include <bits/stdc++.h>

using namespace std;

struct Node {
	int y, v;
	Node(int _y, int _v) {
	 y = _y;
	  v = _v;
	  }
};

vector<Node> edge[100001];
int n, m, k, dist[100001];
bool b[100001];

inline void Dijkstra(int s, int t) {
	memset(dist, 127, sizeof(dist));
	memset(b, false, sizeof(b));
	dist[s] = 0;
	while (true) {
		int x = 0;
		for (int i = 1; i <= n; i++)
			if (!b[i] && dist[i] < 1 << 30)
				if (x == 0 || dist[i] < dist[x])
					x = i;
		if (x == t || x == 0)
			break;
		b[x] = true;
		for (auto i : edge[x])
			dist[i.y] = min(dist[i.y], dist[x] + i.v);
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