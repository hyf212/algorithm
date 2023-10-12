#include <bits/stdc++.h>

using namespace std;

int n, a, b, c;

double f(double x) {
	return a * x * x + b * x + c;
}
int main() {
	scanf("%d", &n);
	while (n--) {
		scanf("%d%d%d", &a, &b, &c);
		double L = -500, R = 500;
		for (int i = 1; i <= 100; i++) {
			double M1 = (R - L) / 3 + L;
			double M2 = (R - L) / 3 * 2 + L;
			if (f(M1) > f(M2))
				L = M1;
			else
				R = M2;
		}
		printf("%.10lf\n", f(L));
	}
}