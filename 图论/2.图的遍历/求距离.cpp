#include <bits/stdc++.h>

using namespace std;

int n, m, k, dist[20001], q[20001];
vector<int> edge[20001];

void bfs(int s) {
	int front = 1, rear = 0;
	q[++rear] = s;
	while (front <= rear) {
		int x = q[front];
		for (auto y : edge[x])
			if (dist[y] == -1) {
				dist[y] = dist[x] + 1;
				q[++rear] = y;
			}
		++front;
	}
}
int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	
	for (int i = 1; i <= k; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		memset(dist, 255, sizeof(dist));
		dist[x] = 0;
		bfs(x);
		printf("%d\n", dist[y]);
	}
}