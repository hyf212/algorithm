/*#include <bits/stdc++.h>

using namespace std;

const int N = 5000;
const int M = 10000;
struct Edge {
	int x, y, v;
} edge[M + 1];
int n, m, k, pre[N + 1], dist[N + 1], c[N + 1]; //c数组记录路径

void shortestpath(int s, int t) {
	memset(dist, 127, sizeof(dist));
	memset(pre, 0, sizeof(pre));
	dist[s] = 0;
	while (true) {
		bool ok = false;
		for (int i = 1; i <= m; i++) {
			int x = edge[i].x, y = edge[i].y, v = edge[i].v;
			if (dist[x] < 1 << 30)
				if (dist[x] + v < dist[y]) {
					dist[y] = dist[x] + v;
					pre[y] = x;
					ok = true;
				}
		}
		if (!ok)
			break;
	}
	if (dist[t] < 1 << 30) {
		printf("%d\n", dist[t]);
		int l = 0;
		for (int i = t; i != s; i = pre[i])
			c[++l] = i;
		c[++l] = s;
		for (int i = 1; i <= l; i++)
			printf("%d ", c[i]);
		printf("\n");
	}
	else
		printf("-1\n");
}
int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++)
		scanf("%d%d%d", &edge[i].x, &edge[i].y, &edge[i].v);
	while (k--) {
		int s, t;
		scanf("%d%d", &s, &t);
		shortestpath(s, t);
	}
}*/

#include <bits/stdc++.h>

using namespace std;

const int N = 5000;
const int M = 10000;

vector< pair<int, int> > edge[M + 1];
int n, m, k, dist[N + 1], q[M * N + 1];
bool b[N + 1];

void shortestpath(int s, int t) {
	memset(dist, 127, sizeof(dist));
	memset(b, false, sizeof(b));
	dist[s] = 0;
	b[s] = true;
	int front = 1, rear = 1;
	q[rear] = s;
	while (front <= rear) {
		int x = q[front];
		++front;
		b[x] = false;
		for (auto i : edge[x])
			if (dist[x] <1 << 30)
				if (dist[x] + i.second < dist[i.first]) {
					dist[i.first] = dist[x] + i.second;
					if (!b[i.first]) {
						q[++rear] = i.first;
						b[i.first] = true;
					}
				}
	}
	if (dist[t] < 1 << 30)
		printf("%d\n", dist[t]);
	else
		printf("-1\n");
}
int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		int x, y, v;
		scanf("%d%d%d", &x, &y, &v);
		edge[x].push_back(make_pair(y, v));
		
	}                       
	while(k--) {
		int s, t;
		scanf("%d%d", &s, &t);
		shortestpath(s, t);
	}
}