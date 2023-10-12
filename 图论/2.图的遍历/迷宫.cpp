#include <bits/stdc++.h>

using namespace std;

int D[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n, m, dist[1001][1001], q[1000001][2];
char s[1001][1002];

void bfs(int sx, int sy) {
	int front = 1, rear = 1;
	q[1][0] = sx, q[1][1] = sy;
	while (front <= rear) {
		int x = q[front][0], y = q[front][1];
		++front;
		for (int i = 0; i < 4; i++) {
			int xx = x + D[i][0], yy = y + D[i][1];
			if (xx < 1 || xx > n || yy < 1 || yy > m)
				continue;
			if (s[xx][yy] != 'X' && dist[xx][yy] == -1) {
				dist[xx][yy] = dist[x][y] + 1;
				q[++rear][0] = xx;
				q[rear][1] = yy;
			}
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%s",s[i] + 1);
	int sx, sy, ex, ey;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (s[i][j] == 'S')
				sx = i, sy = j;
			else if (s[i][j] == 'E')
					ex = i, ey = j;
	memset(dist, 255, sizeof(dist));
	dist[sx][sy] = 0;
	bfs(sx, sy);
	printf("%d", dist[ex][ey]);
}