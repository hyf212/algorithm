vector<int> edge[N + 1];
int n, m, q[N + 1], d[N + 1]; //d记录每个点一开始的入度

inline void ToppSort() {
	int front = 1, rear = 0;
	for (int i = 1; i <= n; i++)
		if (!d[i])
			q[++rear] = i;
	while (front  <= rear) {
		int x = q[front];
		++front;
		for (auto y : edge[x])
			if (--d[y] == 0)
				q[++rear] = y;
	}
	if (rear == n) {
		printf("Yes\n");
		//q中记录了一个合法的拓扑序列
	} else
		printf("No\n");
}