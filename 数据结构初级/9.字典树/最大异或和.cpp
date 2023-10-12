#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn = 1e5 + 5;

struct Node {
    ll nex[2];
    Node() {nex[0] = nex[1] = -1;}
}nd[maxn * 35];

ll tp, ans;
ll mi[35], a[maxn];

void init() {
    for(int i = 0; i <= tp; i++)
        nd[i].nex[0] = nd[i].nex[1] = -1;
    tp = ans = 0;
}

void getMi() {
    mi[1] = 1;
    for(ll i = 2; i <= 32; i++)
        mi[i] = mi[i-1] * 2;
}

void insert(ll rt, ll x, ll h) {
    if(!h) return;
    ll t = x / mi[h] ? 1 : 0;
    if(nd[rt].nex[t] == -1)
        nd[rt].nex[t] = ++tp;
    insert(nd[rt].nex[t], x % mi[h], h - 1);
}

void search(ll rt, ll x, ll h, ll nowans) {
    ans = max(ans, nowans);
    if(!h) return;
    ll t = x / mi[h] ? 1 : 0;
    if(nd[rt].nex[!t] != -1)
        search(nd[rt].nex[!t], x % mi[h], h - 1, nowans + mi[h]);
    else 
        search(nd[rt].nex[t], x % mi[h], h - 1, nowans);
}

int main() {
    getMi();
    int n;
    while(cin >> n) {
        for(int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
            insert(0, a[i], 32);
        }

        for(int i = 0; i < n; i++) {
            search(0, a[i], 32, 0);
        }
        cout << ans << endl;
    }
    return 0;
}
