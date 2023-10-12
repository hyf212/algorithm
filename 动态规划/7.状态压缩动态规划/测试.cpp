/*#include <bits/stdc++.h>

using namespace std;

int n, a[21], s[21], f[1 << 20][21], l[21], b[21];
int main(void) {
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
}*/

/*#include <bits/stdc++.h>

using namespace std;

int n, a[19][19], f[1 << 18][19];

int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &a[i][j]);
	memset(f, 127,sizeof(f));
	f[1][1] = 0;
	for (int i = 1; i < 1 << 18; i++)
		for (int j = 1; j <= n; j++)
			if (f[i][j] < 1 << 30)
				for (int k = 1; k <= n; k++)
					if (!(i & (1 << (k - 1))))
						f[i + (1 << (k - 1))][k] = min(f[i + (1 << (k - 1))][k], f[i][j] + a[j][k]);
	int ans = 1 << 30;
	for (int i = 2; i <= n; i++)
		ans = min(ans, f[(1 << n) - 1][i] + a[i][1]);
	printf("%d", ans);
}*/

/*#include <bits/stdc++.h>

using namespace std;

int n, f[1 << 20], a[21];
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	memset(f, 127, sizeof(f));
	f[0] = 0;
	for (int i = 0; i < 1 << n; i++)
		for (int j = 1; j <= n; j++)
			if (!(i & (1 << (j - 1)))) {
				f[i + (1 << (j - 1))] = min(f[i + (1 << (j - 1))], f[i] + a[j]);
				for (int k = j + 1; k <= n; k++)
					if (!(i & (1 << (k - 1))))
						f[i + (1 << (j - 1)) + (1 << (k - 1))] = min(f[i + (1 << (j - 1)) + (1 << (k - 1))], f[i] + (a[j] ^ a[k]));
				break;
			}
	printf("%d", f[(1 << n) - 1]);
	return 0;
}*/

#include <bits/stdc++.h>

using namespace std;

int n, m, f[256], v[256], a[100001];
bool b[256];
int main(void) {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < 1 << m; i++) {
		int cnt = 0;
		for (int j = 1; j <= m; j++)
			if (i & (1 << (j - 1)))
				cnt++;
		if (cnt <= m / 2)
			b[i] = true;
	}
	memset(f, 128, sizeof(f));
	f[0] = 0;
	for (int i = 1; i <= n; i++) {
		memset(v, 128, sizeof(v));
		for (int j = 0; j < 1 << m; j++)
			if (f[j] >= 0) {
				v[j / 2] = max(v[j / 2], f[j]);
				if (b[j / 2 + (1 << (m - 1))])
					v[j / 2 +(1 << (m - 1))] = max(v[j / 2 + (1 << (m - 1))], f[j] + a[i]);
			}
		memcpy(f, v, sizeof(f));
	}
	int ans = 0;
	for (int i = 0; i < 1 << m; i++)
		ans = max(ans, f[i]);
	printf("%d\n", ans);
	return 0;
}