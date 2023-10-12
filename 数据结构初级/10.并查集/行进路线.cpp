#include <bits/stdc++.h>

using namespace std;

int t, n;
long long a[1002][3], f[1002];

int findset(int x) {
	if (x == f[x])
		return x;
	f[x] = findset(f[x]);
	return f[x];
}
int main() {
	scanf("%d", &t);
	while(t--){
		int xe, ye;
		scanf("%d%d", &xe, &ye);
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%lld%lld%lld", &a[i][0], &a[i][1], &a[i][2]);
		for (int i = 0; i <= n; i++)
			f[i] = i;
		a[0][0] = 0, a[0][1] = 0, a[0][2] = 1;
		for (int i = 0; i <= n; i++)
			for (int j = i + 1; j <= n; j++)
				if ( 1LL * (a[i][0] - a[j][0]) * (a[i][0] - a[j][0]) + 1LL * (a[i][1] - a[j][1]) * (a[i][1] - a[j][1])
					<= 1LL * (a[i][2] + a[j][2]) * (a[i][2] + a[j][2])) {
					int fi = findset(i), fj = findset(j);
					if (fi == fj)
						continue;
					f[fi] = fj;
				}
		int idx = -1;
		for (int i = 0; i <= n; i++)
			if ((1LL * a[i][0] - xe) * (a[i][0] - xe) + 1LL * (a[i][1] - ye) * (a[i][1] - ye)
				<= 1LL * (a[i][2] * a[i][2]))
				idx = i;
		if (idx != -1 && findset(0) == findset(idx))
			printf("1\n");
		else
			printf("0\n");
	}
	return 0;	
}