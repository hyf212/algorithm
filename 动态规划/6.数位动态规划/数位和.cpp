/*#include <bits/stdc++.h>

using namespace std;

int a[21];
long long l, r, ans[10], f[17];

inline void calc(long long n, int xs) {
    int m = 0;
    for (; n; n /= 10)
        a[++m] = n % 10;
    for (int i = 1, j = m; i < j; i++, j--)
        swap(a[i], a[j]);
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j < i; j++)
            ans[a[j]] += xs * a[i] * f[m - i];
        for (int j = 1; j < a[i]; j++)
            ans[j] += xs * f[m - i];
        if (i != 1 && a[i])
            ans[0] += xs * f[m - i];
        if (m != i) {
            for (int j = 1; j < 10; j++)
                ans[j] += xs * f[m - i - 1] * (m - i) * a[i];
            if (i != 1)
                ans[0] += xs * f[m - i - 1] * (m - i) * a[i];
        }
        if (i == 1) {
            if (m >= 2)    
                ans[0] += xs * (a[1] - 1) * (m - 1) * f[m - 2];
            for (int j = 2; j < m; j++)
                ans[0] += xs * 9 * (m - j) * f[m - j - 1];
        }
    }
    for (int i = 1; i <= m; i++)
        ans[a[i]] += xs;
}

int main() {
    f[0] = 1;
    for (int i = 1; i <= 16; i++)
        f[i] = f[i - 1] * 10;
    scanf("%lld%lld", &l, &r);
    calc(r, 1);
    calc(l - 1, -1);
    for (int i = 0; i < 10; i++)
        printf("%lld ", ans[i]);
    printf("\n");
}
*/
#include <bits/stdc++.h>

using namespace std;

int a[21];
long long l, r, ans[11], f[21];

void calc(long long n, int xs) {
	int m = 0;
	for (; n; n /= 10)
		a[++m] = n % 10;
	for (int i = 1, j = m; i < j; i++, j--)
		swap(a[i], a[j]);
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j < i; j++)
			ans[a[j]] += xs * a[i] * f[m - i];
		for (int j = 1; j < a[i]; j++)
            ans[j] += xs * f[m - i];
		if (i != 1 && a[i])
			ans[0] += xs * f[m - i];
		if (m != i) {
            for (int j = 1; j < 10; j++)
                ans[j] += xs * f[m - i - 1] * (m - i) * a[i];
            if (i != 1)
                ans[0] += xs * f[m - i - 1] * (m - i) * a[i];
        }
        if (i == 1) {
            if (m >= 2)    
                ans[0] += xs * (a[1] - 1) * (m - 1) * f[m - 2];
            for (int j = 2; j < m; j++)
                ans[0] += xs * 9 * (m - j) * f[m - j - 1];
        }
    }
    for (int i = 1; i <= m; i++)
        ans[a[i]] += xs;
}

int main(void) {
	scanf("%lld%lld", &l, &r);
	f[0] = 1;
	for (int i = 1; i <= 20; i++)
		f[i] = f[i - 1] * 10;
	calc(r, 1);
	calc(l - 1, -1);
	for (int i = 0; i < 10; i++)
		printf("%lld ", ans[i]);
}