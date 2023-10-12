#include <bits/stdc++.h>

using namespace std;

int a[21];
long long l, r, f[21][10][2];

long long calc(long long n) {
    if (!n)
        return 0;
    int m = 0;
    for (; n; n /= 10)
        a[++m] = n % 10;
    for (int i = 1, j = m; i < j; i++, j--)
        swap(a[i], a[j]);
    long long res = 0;
    bool ok = true;
    for (int i = 1; i <= m && ok; i++) { 
        for (int j = 0; j < a[i]; j++) {
            if (i != 1 && abs(j - a[i - 1]) > 2)
                continue;
            memset(f, 0, sizeof(f));
            if (i == 1 && !j)
                f[i][j][0] = 1;
            else
                f[i][j][1] = 1;
            for (int k = i + 1; k <= m; k++)
                for (int l = 0; l < 10; l++)
                    for (int r = 0; r < 2; r++)
                        if (f[k - 1][l][r])
                            for (int x = 0; x < 10; x++) {
                                if (r && abs(l - x) <= 2)
                                    f[k][x][r] += f[k - 1][l][r];
                                if (!r)
                                    if (!x)
                                        f[k][0][0] += f[k - 1][0][0];
                                    else
                                        f[k][x][1] += f[k - 1][0][0];
                            }
            for (int k = 0; k < 10; k++)
                res += f[m][k][1];
        }
        if (i != 1 && abs(a[i] - a[i - 1]) > 2)
            ok = false;
    }
    if (ok)
        ++res;
    return res;
}

int main() {
    scanf("%lld%lld", &l, &r);
    printf("%lld\n", calc(r) - calc(l - 1));
}