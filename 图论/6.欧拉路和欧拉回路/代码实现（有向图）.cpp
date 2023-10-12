vector<int> edge[N + 1];
int n, m, l, f[N + 1], ind[N + 1], outd[N + 1], c[M + 2], v[N + 1];

inline void dfs(int x) {
    int len = edge[x].size();
    while(f[x] < len) { // f[x] 是记录第x号点，接下来应该走第几个点
        int y = edge[x][f[x]];
        f[x]++;
        dfs(y);
        c[++l] = y; // 记录欧拉路
    }
}

inline void Euler() {
    int x = 0, y = 0, z = 0;
    for(int i = 1; i <= n; i++) {
        if(ind[i] + 1 == outd[i])
            x = i, ++y;
        if(ind[i] != outd[i])
            ++z;
    }

    if(!((y == 1 && z == 2) || !z)) {
        printf("No\n");
        return;
    }

    if(!x)
        for(int i = 1; i <= n; i++)
            if(ind[i])
                x = i;
    memset(f, 0, sizeof(f));
    l = 0;
    dfs(x);
    c[++l] = x;
    if (l == m + 1)
    	printf("Yes\n");
    else
    	printf("No\n");
    for(int i = l; l; --i)
        printf("%d", c[i]);
}