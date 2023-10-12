#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 501;

int n, f[N][N];
int a[N];
int main()
{
    memset(f, 127, sizeof f);
    cin >> n;
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
 
    for(int i = 1; i <= n; i ++) f[i][i] = 0;
    for(int i = 1; i < n; i ++)
    {
        for(int j = 1; j <= n - i; j ++)
        {   
            if(i == 1) f[j][j + i] = 0;
            else 
            {
                for(int k = j + 1; k < j + i; k ++)
                {
                    f[j][j + i] = min(f[j][j + i], f[j][k] + f[k][j + i] + a[j] * a[j + i] * a[k]);
                }
                
            }
            
        }
    }
    cout << f[1][n] << endl;
    return 0;
}

