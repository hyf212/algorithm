#include <bits/stdc++.h>

using namespace std;

const int N = 800;
struct Node {
	int y;
	double v;
	Node (int _y, double _v) {y = _y; v = _v;}
};
int n;
double f[N + 1][N + 1], a[N + 1][2], dist[N + 1];
bool b[N + 1];
vector<Node> edge[N + 1];

inline void Prim() {
	memset(b, false, sizeof(b));
	for (int i = 1; i <= n; i++)
		dist[i] = 1e60;
	dist[1] = 0;
	double ans = 0;
	for (int i = 1; i <= n; i++) {
		int x = 0;
		for (int i = 1; i <= n; i++)
			if (!b[i] && dist[i] != 1e60)
				if (x == 0 || dist[i] < dist[x])
					x = i;
		ans += dist[x];
		b[x] = true;
		for (auto i : edge[x])
			dist[i.y] = min(dist[i.y], i.v);
	}
	printf("%.1f", ans);
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%lf%lf", &a[i][0], &a[i][1]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			f[i][j] = sqrt((a[i][0] - a[j][0]) * (a[i][0] - a[j][0]) + (a[i][1] - a[j][1]) * (a[i][1] - a[j][1]));
	for (int i = 1; i < n; i++)
		for (int j = i + 1; j <= n; j++) {
			edge[i].push_back(Node(j, f[i][j]));
			edge[j].push_back(Node(i, f[i][j]));
		}
	Prim();
	return 0;
}