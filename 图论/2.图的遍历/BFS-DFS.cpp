//图上的BFS
int n, m, dist[N + 1], q[N + 1];
vector<int> edge[N + 1];

void bfs(int s) { // s表示起点的编号
	memset(dist, 255, sizeof(dist));
	dist[s] = 0;
	int front = 1, rear = 0;
	q[++rear] = s;
	while (front <= rear) {
		int x = q[front];
		++front;
		for (auto y : edge[x])
			if (dist[y] == -1) {
				dist[y] = dist[x] + 1;
				q[++rear] = y;
			}
	}
}

//网格图的BFS四连通
int D[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n, m, dist[N + 1]{M + 1}, q[N * M + 1][2];
char s[N + 1][M + 2];

void bfs(int sx, int sy) {
	 memset(dist, 255, sizeof(dist));
	 dist[sx][sy] = 0;
	 int front = 1, rear = 0;
	 q[++rear][0] = sx; q[++rear][1] = sy;
	 while (front <= rear) {
	 	int x = q[front][0], y = q[front][1];
	 	++front;
	 	for (int i = 0; i < 4; i++) {
	 		int xx = x + D[i][0], yy = y + d[i][1];
	 		if (xx < 1 || x > n || yy < 1 || yy > m)
	 			continue;
	 		if (s[xx][yy] != 'X' && dist[xx][yy] == -1) { // 'X'为障碍
	 			dist[xx][yy] = dist[x][y] + 1;
	 			q[++rear][0] = xx; q[rear][1] = yy;
			 }
		 }
	 }
}

//图上的DFS
int n, m;
bool b[N + 1];
vector<int> edge[N + 1];

inline void dfs(int x) {
	b[x] = true;
	for (auto y : edge[x])
		if (!b[y])
			dfs(y);
}

int main() {
	...
	memset(b, false, sizeof(b));
	dfs(s); // s表示起点编号
}