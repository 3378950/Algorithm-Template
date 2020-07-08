#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;
const int N = 1010;
int v[N], w[N];
int n, m;

void solve1() {
    int dp[1010][1010];
    for(int i = 1; i <= n; i++) 
        for(int j = 0; j <= m; j++) {
            dp[i][j] = dp[i - 1][j];
            if(j >= v[i]) dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i]] + w[i]);
        }
    printf("%d", dp[n][m]);
}

void solve2() {
    int dp[1010];
    for(int i = 1; i <= n; i++) {
        for(int j = m; j >= v[i]; j--) {
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    }
    printf("%d", dp[m]);
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d%d", &v[i], &w[i]);

    // solve1();

    solve2();

    return 0;
            
}