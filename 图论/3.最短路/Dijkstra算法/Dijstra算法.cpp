时间复杂度为O(n^2 + m)
struct Node {
	int y, v;
	Node (int x, int y) {
		y = _y;
		v = _v;
	}
}

vector<Node> edge[N + 1];
int n, m, dist[N + 1];
bool b[N + 1];
 
int Dijkstra(int s, int t) {
	memset(b, false, sizeof(b));
	memset(dist, 127, sizeof(dist));
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
	return dist[t];
} 
=========================================================================
时间复杂度为O((m + n)log(n))
优化：
struct Node {
	int y, v;
	Node (int x, int y) {
		y = _y;
		v = _v;
	}
};
set< pair<int, int> > q;
vector<Node> edges[N + 1];
bool b[N + 1];
int n, m, dist[N + 1];
int Dijkstra(int s, int t) {
	memset(dist, 127, sizeof(dist));
	memset(b, false, sizeof(b));
	dist[s] = 0;
	for (int i = 1; i <= n; i++)
		q.insert(make_pair(dist[i], i));
	while (!q.empty()) {
		int x = q.begin()->second;
		q.erase(q.begin());
		if (x == t || dist[x] > 1 << 30)
			break;
		b[x] = true;
		for (auto i : edge[x]) {
			if (!b[i.y] && dist[x] + i.v < dist[i.y]) {
				q.erase({dist[i.y], i.y});
				dist[i.y] = dist[x] + i.v;
				q.insert(make_pair(dist[i.y], i.y));
			}
		}
		
	}
	return dist[t];
}