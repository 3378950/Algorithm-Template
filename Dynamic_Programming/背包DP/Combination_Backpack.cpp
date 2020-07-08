#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 110;
int v[N][N], w[N][N], s[N];
int dp[N];
int n, m;

int main() {
    scanf("%d%d", &n, &m);
    
    for(int i = 1; i <= n; i++) {
        scanf("%d", &s[i]);
        for(int j = 0; j < s[i]; j++)
            scanf("%d%d", &v[i][j], &w[i][j]);
    }
    for(int i = 1; i <= n; i++) 
        for(int j = m; j >= 0; j--)
            for(int k = 0; k < s[i]; k++)
                if(v[i][k] <= j)
                    dp[j] = max(dp[j], dp[j - v[i][k]] + w[i][k]);
                    
    printf("%d\n", dp[m]);
    return 0;
}