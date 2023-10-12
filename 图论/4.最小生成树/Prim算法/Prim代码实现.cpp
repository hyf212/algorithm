//Prim算法
时间复杂度为O(n^2)
struct Node {
	int y, v;
	Node (int _y, int _v){y = _y; v = _v;}
};

vector<Node> edge[N + 1];
int n, m, dist[N + 1];
bool b[N + 1];

int Prim() {
	memset(b, false, sizeof(b));
	memset(dist, 127, sizeof(dist));
	dist[1] = 0;
	int ans = 0, tot = 0;
	while (true) {
		int x = 0;
		for (int i = 1; i <= n; i++)
			if (!b[i] && dist[i] < 1 << 30)
				if (x == 0 || dist[i] < dist[x])
					x = i;
		if (x == 0)
			break;
		++tot;
		ans += dist[x];
		b[x] = true;
		for (auto i : edge[x])
			dist[i.y] = min(dist[i.y], i.v);
	}
	if (tot != n)
		return -1;
	else
		return ans;
}


==================================================================================
时间复杂度为O((m + n)log(n))
//算法优化
struct Node {
	int y, v;
	Node (int _y, int _v){y = _y; v = _v;}
};
set< pair<int, int> > q;
vector<Node> edge[N + 1];
int n, m, dist[N + 1];
bool b[N + 1];

int Prim() {
	memset(b, false, sizeof(b));
	memset(dist, 127, sizeof(dist));
	dist[1] = 0;
	q.clear();
	for (int i = 1; i <= n; i++)
		q.insert(make_pair(dist[i], i));
	int ans = 0, tot = 0;
	while (!q.empty()) {
		int x = q.begin()->second;
		q.erase(q.begin());
		if (dist[x] >  1 << 30)
			break;
		++tot;
		ans += dist[x];
		b[x] = true;
		for (auto i : edge[x])
			if (!b[i.y] && i.v < dist[i.y]) {
				q.erase(make_pair(dist[i.y], i.y));
				dist[i.y] = min(dist[i.y], i.v);
				q.insert(make_pair(dist[i.y], i.y));
			}	
	} 
	if (tot != n)
		return -1;
	else
		return ans;
}