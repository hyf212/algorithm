#include <bits/stdc++.h>

using namespace std;

struct node {
    node *next;
    int where;
} *first[100001], a[200001];

int n, l, f[100001][2][2], v[100001];
bool b[100001];

inline void makelist(int x, int y) {
    a[++l].where = y;
    a[l].next = first[x];
    first[x] = &a[l];
}

inline void up(int i) {
    b[i] = true;
    for (node *x = first[i]; x; x = x->next)
        if (!b[x->where]) {
            up(x->where);
            if (f[x->where][0][0] + 1 > f[i][0][0])
                f[i][1][0] = f[i][0][0], f[i][1][1] = f[i][0][1], f[i][0][0] = f[x->where][0][0] + 1, f[i][0][1] = x->where;
            else
                if (f[x->where][0][0] + 1 > f[i][1][0])
                    f[i][1][0] = f[x->where][0][0] + 1, f[i][1][1] = x->where;
        }
}

inline void down(int i) {
    b[i] = true;
    for (node *x = first[i]; x; x = x->next)
        if (!b[x->where]) {
            if (f[i][0][1] == x->where)
                if (v[i] > f[i][1][0])
                    v[x->where] = v[i] + 1;
                else
                    v[x->where] = f[i][1][0] + 1;
            else
                v[x->where] = max(f[i][0][0], v[i]) + 1;
            down(x->where);
        }
}

int main() {
    memset(first, 0, sizeof(first));
    l = 0;
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        makelist(x, y);
        makelist(y, x);
    }
    memset(b, false, sizeof(b));
    up(1);
    memset(b, false, sizeof(b));
    down(1);
    for (int i = 1; i <= n; i++)
        printf("%d\n", f[i][0][0] + f[i][1][0] + v[i] - min(min(f[i][0][0], f[i][1][0]), v[i]));
}