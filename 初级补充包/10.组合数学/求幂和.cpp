#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2010;

int n, m, p;
ll comb[N][N], inv[N], s[N];
int main() {
	scanf("%d%d%d", &n, &m, &p);
	for (int i = 0; i <= n + 1; i++) {
		comb[i][0] = comb[i][i] = 1;
		for (int j = 1; j < i; j++)
			comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % p;	
	}
	inv[1] = 1;
	for (int i = 2; i <= n + 1; i++)
		inv[i] = (p - p / i) * inv[p % i] % p;
	ll pw = m + 1;
	s[0] = m;
	for (int i = 1; i <= n; i++) {
		pw = pw * (m + 1) % p;
		s[i] = (pw - 1);
		for (int j = 0; j < i; j++)
			s[i] = (s[i] - s[j] * comb[i + 1][j]) % p;
		s[i] = s[i] * inv[i + 1] % p;
	}
	if (s[n] < 0) s[n] += p;
	printf("%lld", s[n]);
}
 
