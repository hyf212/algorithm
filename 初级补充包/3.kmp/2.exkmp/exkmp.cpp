#include <bits/stdc++.h>

using namespace std;

void exkmp() {
	int L = 1, R = 0;
	z[1] = 0;
	for (int i = 2; i <= n; i++) {
		if (i > R)
			z[i] = 0;
		else {
			int k = i - L + 1;
			z[i] = min(z[k], R - i + 1);
		}
		while (i + z[i] <= n && s[z[i] + 1] == s[i + z[i]])
			++z[i];
		if (i + z[i] - 1 > R)
			L = i, R = i + z[i] - 1;
	}
}
int main(void) {
	return 0;
}
