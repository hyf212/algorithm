#include <bits/stdc++.h>

using namespace std;

int n, f[301][301], c[301], a[301];
bool b[301];
int main() {
	scanf("%d", &n);
	memset(f, 17, sizeof(f));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &f[i][j]);
	for (int i = 1; i <= n; i++)
		scanf("%d", &c[i]);
		
	for (int l = n; l; l--) {
		int k = c[l];
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (f[i][k] < 1 << 30 && f[k][j] < 1 << 30)
					f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
		b[k] = true;
		int ans = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (b[i] && b[j])
					ans += f[i][j];
		a[l] = ans;
	}
	for (int i = 1; i <= n; i++)
		printf("%d ", a[i]);
		
}