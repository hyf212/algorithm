#include<bits/stdc++.h>

using namespace std;

const int base = 101, p = 9999971;
const int base2 = 137, p2 = 9999973;
int n, m, ha[200005], hb[200005], c[200005], ha2[200005], hb2[200005], c2[200005];
char a[200005], b[200005];
int main(void) {
	scanf("%d%d", &n, &m);
	scanf("%s%s", a + 1, b + 1);
	c[0] = 1, c2[0] = 1;
	for (int i = 1; i <= 200005; i++)
		c[i] = c[i - 1] * base % p,
		c2[i] = c2[i - 1] * base2 % p2;
	for (int i = 1; i <= n; i++)
		ha[i] = (ha[i - 1] * base + a[i] - 'a' + 1) % p,
		ha2[i] = (ha2[i - 1] * base2 + a[i] - 'a' + 1) % p2;
	for (int i = 1; i <= m; i++)
		hb[i] = (hb[i - 1] * base + b[i] - 'a' + 1) % p,
		hb2[i] = (hb2[i - 1] * base2 + b[i] - 'a' + 1) % p2;
	int ans = 0;
	for (int i = 1; i + m - 1 <= n; i++) 
		if((ha[i + m - 1] - 1ll * ha[i - 1] * c[m] % p + p) % p == hb[m] &&
		 (ha2[i + m - 1] - 1ll * ha2[i - 1] * c2[m] % p2 + p2) % p2 == hb2[m])
			++ans;
	printf("%d", ans);
	return 0;
}