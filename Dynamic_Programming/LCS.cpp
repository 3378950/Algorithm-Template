#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1010;
int dp[N][N];
char s[N], p[N];
int n, m;

int main() {
    scanf("%d%d", &n, &m);
    scanf("%s%s", s + 1, p + 1);

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if(s[i] == p[j]) dp[i][j] = max(dp[i - 1][j - 1] + 1, dp[i][j]);
        }

    printf("%d\n", dp[n][m]);
    return 0;

}
