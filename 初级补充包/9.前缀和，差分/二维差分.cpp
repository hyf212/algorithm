#include <bits/stdc++.h>

using namespace std;

int n, m, q;
const int N = 2002;
unsigned int A, B, C;
long long a[N][N];
inline unsigned int rng61() {
    A ^= A << 16;
    A ^= A >> 5;
    A ^= A << 1;
    unsigned int t = A;
    A = B;
    B = C;
    C ^= t ^ A;
    return C;
}
int main(){
    scanf("%d%d%d%u%u%u", &n, &m, &q, &A, &B, &C);
    for (int i = 1; i <= q; i++) {
        int x1 = rng61() % n + 1, x2 = rng61() % n + 1;
        int y1 = rng61() % m + 1, y2 = rng61() % m + 1;
        unsigned int d = rng61();
        if (x1 > x2) swap(x1, x2);
        if (y1 > y2) swap(y1, y2);
        // 执行修改操作
        a[x1][y1] += d;
        a[x2 + 1][y2 + 1] += d;
        a[x1][y2 + 1] -= d;
        a[x2 + 1][y1] -=d;
    }
    for (int i = 1; i <= n; i++)
    	for (int j = 1; j <= m; j++)
    		a[i][j] += a[i][j - 1];
    for (int i = 1; i <= n; i++)
    	for(int j = 1; j <= m; j++)
    		a[i][j] += a[i - 1][j];
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    	for (int j = 1; j <= m; j++)
    		ans ^= a[i][j];
    printf("%lld\n", ans);
}