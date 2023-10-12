#include <bits/stdc++.h>

using namespace std;

vector<int> edge[801];
int D[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n, m, a[41][41], n1, n2, r[41][41], v[801];
bool b[801];
bool find(int x) {
	b[x] = true;
	for (auto y : edge[x])
		if (!v[y] || (!b[v[y]] && find(v[y]))) {
			v[y] = x;
			return true;
		}
	return false;
}
int match() {
	int ans = 0;
	memset(v, 0, sizeof(v));
	for (int i = 1; i <= n1; i++) {
		memset(b, false, sizeof(b));
		if (find(i))
			++ans;
	}
	return ans;
}
int main() {
	scanf("%d%d", &n, &m);
	memset(a, 0, sizeof(a));
	n1 = n2 = 0;
	for (int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		a[x][y] = 1;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (!a[i][j])
				if ((i + j) & 1)
					r[i][j] = ++n2;
				else
					r[i][j] = ++n1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (!a[i][j] && !((i + j) & 1))
				for (int k = 0; k < 4; k++) {
					int x = i + D[k][0], y = j + D[k][1];
					if (x < 1 || x > n || y < 1 || y > n || a[x][y])
						continue;
					edge[r[i][j]].push_back(r[x][y]);
				}
	printf("%d\n", 2 * match());
}