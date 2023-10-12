#include <bits/stdc++.h>

using namespace std;

int test, n;
char s[200001];

int solve(int l, int r, int x) {
	if (l == r)
		if (x == s[l])
			return 0;
		else
			return 1;
	int m = (l + r) / 2;
	int y1 = 0, y2 = 0;
	for (int i = l; i <= m; i++)
		if (s[i] != x)
			++y1;
	for (int i = m + 1; i <= r; i++)
		if (s[i] != x)
			++y2;
	return min(y2 + solve(l, m, x + 1), y1 + solve(m + 1, r, x + 1));
}
int main() {
	scanf("%d", &test);
	while (test--) {
		scanf("%d%s", &n, s + 1);
		printf("%d\n", solve(1, n, 'a'));
	}
}