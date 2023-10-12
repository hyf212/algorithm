#include <bits/stdc++.h>

using namespace std;

struct node {
    node *next;
    int where, v;
} *first[100001], a[200001];

int n, l;
long long f[100001], v[100001];
bool b[100001];

inline void makelist(int x, int y, int z) {
    a[++l].where = y;
    a[l].v = z;
    a[l].next = first[x];
    first[x] = &a[l];
}

inline void up(int i) {
    b[i] = true;
    bool ok = true;
    for (node *x = first[i]; x; x = x->next)
        if (!b[x->where]) {
            up(x->where);
            f[i] += min(1LL * x->v, f[x->where]);
            ok = false;
        }
    if (ok)
        f[i] = 1 << 30;
}

inline void down(int i) {
    b[i] = true;
    for (node *x = first[i]; x; x = x->next)
        if (!b[x->where]) {
            if (v[i] + f[i] - min(1LL * x->v, f[x->where]))
                v[x->where] = min(v[i] + f[i] - min(1LL * x->v, f[x->where]), 1LL * x->v);
            else
                v[x->where] = x->v;
            down(x->where);
        }
}

int main() {
    memset(first, 0, sizeof(first));
    l = 0;
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        makelist(x, y, z);
        makelist(y, x, z);
    }
    memset(b, false, sizeof(b));
    up(1);
    memset(b, false, sizeof(b));
    down(1);
    for (int i = 1; i <= n; i++)
        if (f[i] != 1 << 30)
            printf("%lld\n", f[i] + v[i]);
        else
            printf("%lld\n", v[i]);
}