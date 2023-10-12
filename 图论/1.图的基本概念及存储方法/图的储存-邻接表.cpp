int n, m;
int a[N + 1][N + 1];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1 ; i <= m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		a[x][y] = a[y][x] = 1;// 无向简单图
	}
}

//vector容器写法
int n, m;
vector<int> edge[N + 1];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
}

//链表写法
int n, m, l = 0;

struct Node {
	Node *next;
	int where;
} *head[N + 1], a[2 * M + 1];

void addedge(int x, int y) {
	a[++l].where = y;
	a[l].next = head[x];
	head[x] = &a[l];
}