#include <bits/stdc++.h>

using namespace std;

vector<int> edge[27];
int n, m, l, f[27], c[100002], ind[27], outd[27], v[27];

inline void dfs(int x) {
    while(f[x] < v[x]) { // f[x] 是记录第x号点，接下来应该走第几个点
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
//    for(int i = l; l; --i)
//        printf("%d", c[i]);
}
int main() {
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		char str[12];
		scanf("%s", str);
		int x = str[0] - 'a' + 1, y =  str[strlen(str) - 1] - 'a' + 1;
		edge[x].push_back(y);
		v[x]++;
		++outd[x], ++ind[y];
	}
	n = 26;
	Euler();
}