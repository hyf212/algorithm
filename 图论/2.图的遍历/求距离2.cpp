#include <bits/stdc++.h>

using namespace std;

int n, m, k, s, t, dist[20001];
vector< pair<int, int> > edge[20001];
vector<int> c[20001];

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		edge[x].push_back(make_pair(y, z));
		edge[y].push_back(make_pair(x, z));
	}
	while(k--) {
		scanf("%d%d", &s, &t);
		memset(dist, 255, sizeof(dist));
		for (int i = 0; i <= n; i++)
			c[i].clear();
		dist[s] = 0;
		c[0].push_back(s);
		for (int i = 0; !c[i].empty(); i++) {
			int front = 0, rear = c[i].size() - 1;
			while (front <= rear) {
				int x = c[i][front];
				++front;
				for (auto y : edge[x])
					if (!y.second && dist[y.first] == -1) {
						dist[y.first] = dist[x];
						c[i].push_back(y.first);
						rear++;
					}
			}
			if (dist[t] != -1) {
				break;
			}
			for (int j = 0; j <= rear; j++) {
				int x = c[i][j];
				for (auto y : edge[x])
					if (y.second && dist[y.first] == -1) {
						dist[y.first] = dist[x] + 1;
						c[i + 1].push_back(y.first);
					}
			}
				
		}
		printf("%d\n", dist[t]);
			
	}
}