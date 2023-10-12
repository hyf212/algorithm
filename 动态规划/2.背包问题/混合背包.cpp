#include<bits/stdc++.h>

using namespace std;

int n, m, a[1001], v[1001], w[1001], f[1001], l[1001];
vector<int> c[1001];
int main(void) {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d", &a[i], &v[i], &w[i]);
		if (a[i] == 3)
			scanf("%d", &l[i]);
		c[a[i]].push_back(i);
	}
	for (int i = 1; i <= 3; i++) {
		if (i == 1) {
			for (auto k : c[i])
				for (int j = m; j; j--)
					if (j >= v[k])
						f[j] = max(f[j], f[j - v[k]] + w[k]);
		} else if (i == 2) {
			for (auto k : c[i])
				for (int j = v[k]; j <= m; j++)
					f[j] = max(f[j], f[j - v[k]] + w[k]);
		} else {
			for (auto j : c[i])
				for (int k = 1; k <= l[j]; k++)
					for (int p = m; p >= v[j]; p--)
						f[p] = max(f[p], f[p - v[j]] + w[j]);
		}
	}
	printf("%d", f[m]);
	return 0;
		
}