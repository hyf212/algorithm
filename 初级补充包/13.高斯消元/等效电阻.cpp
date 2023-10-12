#include <bits/stdc++.h>

using namespace std;

const int N = 51;
const double eps = 1e-10;
int n, m;
double a[N][N], b[N], r[N][N], f[N];
inline void gauss() {
	n -= 2;
	int l = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = l + 1; j <= n; j++)
			if(abs(a[j][i]) > abs(a[l][i])) {
				for (int k = i; k <= n; k++)
					swap(a[j][k], a[l][k]);
				swap(b[j], b[l]);
			}
		if (abs(a[l][i]) < eps)
			continue;
		for (int j = 1;j <= n; j++)
			if (j != l && abs(a[j][i]) >= eps) {
				double delta  = a[j][i] / a[l][i];
				for (int k = i; k <= n; k++)
					a[j][k] -= a[l][k] * delta;
				b[j] -= b[l] * delta;
			}
		++l;
	}
	f[1] = 1, f[n + 2] = 0;
	for (int i = 1; i <= n; i++)
		f[i + 1] = b[i] / a[i][i];
	n += 2;
	double x = 0;
	for (int i = 2; i <= n; i++)
		if (abs(r[1][i]) >= eps)
			x += (f[1] - f[i]) * r[1][i];
	printf("%.10f\n", 1. / x); 
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		r[x][y] += 1. / z;
		r[y][x] += 1. / z;
	}
	for (int i = 2; i < n; i++)
		for (int j = 1; j <= n; j++)
			if (abs(r[i][j]) >= eps) {
				if (j == 1)
					b[i - 1] += r[i][j];
				else
					if (j < n)
						a[i - 1][j - 1] -= r[i][j];
				a[i - 1][i - 1] += r[i][j];
			}
	gauss();
}