/*#include <bits/stdc++.h>

using namespace std;

int n, a[21], f[1 << 20];
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
			}
	printf("%d", f[(1 << n) - 1]);
	return 0;
}*/
#include <bits/stdc++.h>

using namespace std;

int n, a[21], f[1 << 20];
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
}