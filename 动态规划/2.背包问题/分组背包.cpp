/*#include<bits/stdc++.h>

using namespace std;

int n, m, a[1001], v[1001], w[1001], f[1001][1001];
vector<int> c[1001];
int main(void) {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d", &a[i], &v[i], &w[i]);
		c[a[i]].push_back(i);
	}	
	for (int i = 1; i <= 1000; i++)
		for (int j = 0; j <= m; j++) {
			f[i][j] = f[i - 1][j];
			for (auto k : c[i])
				if (v[k] <= j)
					f[i][j] = max(f[i - 1][j], f[i - 1][j - v[k]] + w[k]);
		}
	printf("%d", f[1000][m]);
	return 0;
}*/
#include<bits/stdc++.h>

using namespace std;

int n, m, a[1001], v[1001], w[1001], f[1001];
vector<int> c[1001];
int main(void) {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d", &a[i], &v[i], &w[i]);
		c[a[i]].push_back(i);
	}
	for (int i = 1; i <= 1000; i++)
		for (int j = m; j; j--)
			for (auto k : c[i])
				if (j >= v[k])
					f[j] = max(f[j], f[j - v[k]] + w[k]);
	printf("%d", f[m]);
}