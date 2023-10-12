vector<int> edges[N + 1];
int n, father[N + 1];

void addedge(int x, int y) {
	edges[x].push_back(y);
}
//遍历x的所有儿子
int l = edges[x].size();
for (int i = 0; i < l; i++) {
	edges[x][i]
	.....
}

for (auto i : edges[x]) {
	.....
}