#include <bits/stdc++.h>

using namespace std;

int n, m, d[101];
double f[101];
vector<int> c[101];
int main(void) {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		c[x].push_back(y);
		d[x]++;
	}
	f[1] = 1.0;
	for (int i = 1; i <= n; i++)
		for (auto j : c[i])
			f[j] += f[i] / d[i];
	printf("%.10f\n", f[n]);
	return 0;
}