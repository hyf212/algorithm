#include <bits/stdc++.h>

using namespace std;

const int N = 1000;
struct Node {
	int y, v;
	Node (int _y, int _v){y = _y; v = _v;}
};

vector<Node> edge[N + 1];
int n, m, dist[N + 1];
bool b[N + 1];

void Prim() {
	memset(b,false, sizeof(b));
	memset(dist, 127, sizeof(dist));
	dist[1] = 0;
	int ans = 0, tot = 0;
	while (true) {
		int x = -1;
		for (int i = 1; i <= n; i++)
			if (!b[i] && dist[i] < 1 << 30)
				if (x == -1 || dist[i] < dist[x])
					x = i;
		if (x == -1)
			break;
		++tot;
		b[x] = true;
		ans += dist[x];
		for (auto i : edge[x])
			dist[i.y] = min(dist[i.y], i.v);
	}
	if (tot != n)
		printf("-1\n");
	else
		printf("%d\n", ans);
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		edge[x].push_back(Node(y, z));
		edge[y].push_back(Node(x, z));
	}
	Prim();
	return 0;
}