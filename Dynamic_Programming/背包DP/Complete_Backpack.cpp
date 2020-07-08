#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1010;
int v[N], w[N];
int n, m;

void solve1() {
    int dp[N][N];
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            dp[i][j] = dp[i - 1][j];
            if(v[i] <= j) dp[i][j] = max(dp[i][j], dp[i][j - v[i]] + w[i]);
        }
    }
        
    printf("%d\n", dp[n][m]);
}

void solve2() {
    int dp[N];
    for(int i = 1; i <= n; i++) {
        for(int j = v[i]; j <= m; j++) 
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
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