/*#include<bits/stdc++.h>

using namespace std;

const int P = 9999971;
int n, m, a[200001], b[200001];
vector<int> c[P];
int main(void) {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= m; i++)
		scanf("%d", &b[i]);
	for (int i = 1; i < P; i++)
		c[i].clear();
	for (int i = 1; i <= n; i++)
		c[a[i] % P].push_back(a[i]);
	int x = 0;
	for (int i = 1; i <= m; i++) {
		int v = b[i] % P;
		int l = c[v].size();
		bool ok = false;
		for (int j = 0; j < l && !ok; j++)
			if (c[v][j] == b[i])
				ok = true;
		if (ok)
				x++;
	}
	if (2 * x >= m)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}*/
#include<bits/stdc++.h>

using namespace std;

unordered_map<int, int> c;
int n, m, a[200001], b[200001];
int main(void) {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= m; i++)
		scanf("%d", &b[i]);
	c.clear();
	for (int i = 1; i <= n; i++)
		c[a[i]] = 1;
	int x = 0;
	for (int i = 1; i <= m; i++)
		if (c.find(b[i]) != c.end())
			x++;
	if (2 * x >= m)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}