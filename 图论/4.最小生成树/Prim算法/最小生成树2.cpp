#include <bits/stdc++.h>
 
using namespace std;

const int N = 50000;
struct Node {
	int y, v;
	Node (int _y, int _v) {v = _v; y = _y;}
};
set< pair<int, int> > q;
vector<Node> edge[N + 1];
int n, m, dist[N + 1];
bool b[N + 1];

inline void prim() {
	memset(dist, 127, sizeof(dist));
	memset(b, false, sizeof(b));
	dist[1] = 0;
	q.clear();
	for (int i = 1; i <= n; i++)
		q.insert(make_pair(dist[i], i));
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int x = q.begin()->second;
		q.erase(q.begin());
		ans += dist[x];
		b[x] = true;
		for (auto i : edge[x])
			if (!b[i.y] && i.v < dist[i.y]) {
				q.erase(make_pair(dist[i.y], i.y));
				dist[i.y] = min(dist[i.y], i.v);
				q.insert(make_pair(dist[i.y], i.y));
			}
	}
	printf("%d", ans);
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		edge[x].push_back(Node(y, z));
		edge[y].push_back(Node(x, z));
	}
	prim();
	return 0;
}

