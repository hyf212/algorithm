/*#include <bits/stdc++.h>

using namespace std;

int n, a[21], l[21], b[21], c[21][21];
int main() { 
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &l[i]);
		for (int j = 1; j <= l[i]; j++)
			scanf("%d", &c[i][j]);
	}
	int ans = 0;
	for (int i = 0; i < 1 << n; i++) {
		for (int j = 1, k = i; j <= n; j++, k /= 2)
			b[j] = k & 1;
		bool ok = true;
		for (int j = 1; j <= n && ok; j++)
			if (b[j] && l[j]) {
				int cnt = 0;
				for (int k = 1; k <= l[j]; k++)
					if (b[c[j][k]])
						++cnt;
				if (cnt == l[j])
					ok = false;
			}
		if (!ok)
			continue;
		int res = 0;
		for (int j = 1; j <= n; j++)
			if (b[j])
				res += a[j];
		ans = max(ans, res);
	}
	printf("%d", ans);
	return 0;
}*/

#include <bits/stdc++.h>

using namespace std;

int n, a[21], l[21], b[21], s[21];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &l[i]);
		for (int j = 1; j <= l[i]; j++) {
			int x;
			scanf("%d", &x);
			s[i] |= (1 << (x - 1));
		}
	}
	int ans = 0;
	for (int i = 0; i < 1 << n; i++) {
		for (int j = 1, k = i; j <= n; j++, k /= 2)
			b[j] = k & 1;
		bool ok = true;
		for (int j = 1; j <= n && ok; j++)
			if (b[j] && l[j] && (i & s[j]) == s[j])
				ok = false;
		if (!ok)
			continue;
		int res = 0;
		for (int j = 1; j <= n; j++)
			if (b[j])
				res += a[j];
		ans = max(ans, res);
	}
	printf("%d", ans);
	return 0;
}