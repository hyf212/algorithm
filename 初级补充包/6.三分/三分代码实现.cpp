double f(x) {...}

double calc() {
	double L = 0, R = 1e10;
	for (int i = 1; i <= 100; i++) {
		double M1 = (R - L) / 3 + L;
		double M2 = (R - L) / 3 * 2 + L;
			L = M1;
		else
			R = M2;
	}
	return f[L];
}