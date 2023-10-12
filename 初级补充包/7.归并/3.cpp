#include <bits/stdc++.h>

using namespace std;

int t, n;
long long gcd(int i, int j) {
	long long rem;
	int x = i, y = j;
	while (y) {
		rem = y % x;
		y = y / x;
		x = rem;
	}
	return x;
}
//long long lcm(int x, int y) {
//	return x * y / gcd(x, y);
//}
int main() {
	scanf("%d", &t); 
	while (t--) {
		scanf("%d", &n);
		int ans = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n ; j++)
				if (3 * gcd(i, j) * gcd(i, j) >= 1LL * i * j)
					ans += 2;
		ans += n;
		printf("%d\n", ans);
	}
	
}