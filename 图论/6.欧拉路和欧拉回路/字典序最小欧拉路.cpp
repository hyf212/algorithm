#include <bits/stdc++.h>

using namespace std;

struct Node {
	int y, idx;
	Node(int _y, int _idx) { y = _y; idx = _idx;}
	bool operator < (const Node &A) const {
		return y < A.y;
	}
};

vector <Node> edge[100001];

int n, m, l, cnt = 1, f[100001], v[100001], c[100002], d[1000001];

bool b[200002];

inline void dfs(int x) {
	while (f[x] < v[x]) {
		int y = edge[x][f[x]].y, idx = edge[x][f[x]].idx;
		if (!b[idx]) {
			++f[x];
			b[idx] = b[idx ^ 1] = true;
			dfs(y);
			c[++l] = y;
		} else
			++f[x];
		
	}
}

inline void Euler() {
	int x = 0;
	for (int i = 1; i <= n; i++)	
		if (d[i]) {
			x = i;
			break;
		}
	memset(f, 0, sizeof(f));
	memset(b, false, sizeof(b));
	l = 0;
	dfs(x);
	c[++l] = x;
	for (int i = l; i; --i)
		printf("%d ", c[i]);
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		++d[x]; ++d[y];
		++v[x]; ++v[y];
		edge[x].push_back(Node(y, ++cnt));
		edge[y].push_back(Node(x, ++cnt));
	}
	for (int i = 1; i <= n; i++)
		sort(edge[i].begin(), edge[i].end());
	Euler();
}