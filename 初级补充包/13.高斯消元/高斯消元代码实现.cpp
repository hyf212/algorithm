const int N = 100;

const double eps = 1e-10;
double a[N + 1][N + 1], b[N + 1];

inline void gauss() {
	int l = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = l + 1; j <= n; j++)
			if (abs(a[j][i]) > abs(a[l][i])) {
				for (int k = i; k <= n; k++)			
					swap(a[l][k], a[j][k]);
				swap(b[l], b[j]);
			}
		if (abs(a[l][i]) < eps)
			continue;
		for (int j = 1; j <= n; j++)
			if (j != l && abs(a[j][i]) >= eps) {
				double delta = a[j][i] / a[l][i];
				for (int k = i; k <= n; k++)
					a[j][k] -= a[l][k] * delta;
				b[j] -= b[l] * delta;
			}
		++l;	
	}
	for (int i = l; i <= n; i++)
		if (abs(b[i]) >= eps) {
			printf("-1\n");//无解
			return;
		}
	if (l <= n)
		printf("-2\n"); //无穷多解
	else
		for (int i = 1; i <= n; i++)
			printf("%.10lf\n", b[i] / a[i][i]);
}