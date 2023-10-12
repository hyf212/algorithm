#include <bits/stdc++.h>

using namespace std;

int n, f[501][501];
char str[501];

int main(void) {
	scanf("%d%s", &n, str + 1);
	memset(f, 0, sizeof(f));
	for (int i = 1; i < n; i++)
		for (int j = 1; j <= n - i; j++) {
			if ((str[j] == '(' && str[i + j] == ')') || (str[j] == '[' && str[i + j] == ']'))
				f[j][j + i] = f[j + 1][j + i - 1] + 2;
			for (int k = j; k < j + i; k++)
				f[j][j + i] = max(f[j][j + i], f[j][k] + f[k + 1][i + j]);

		}
		printf("%d\n", f[1][n]);
		return 0;
}