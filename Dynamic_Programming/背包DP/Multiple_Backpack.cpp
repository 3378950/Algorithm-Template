#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int N = 210;
int v[N], w[N], s[N];
int n, m;


void solve1() {
    int dp[N][N];
    for(int i = 1; i <= n; i++) 
        for(int j = 0; j <= m; j++)
            for(int k = 0; k <= s[i] && k * v[i] <= j; k++)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - k * v[i]] + w[i] * k);
    cout << dp[n][m];
}

void solve2() {
    int dp[N], V[N], W[N];
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        int k = 1;
        while(k <= s[i]) {
            cnt++;
            V[cnt] = k * v[i];
            W[cnt] = k * w[i];
            s[i] -= k;
            k *= 2;
        }
        if(s) {
            cnt++;
            V[cnt] = v[i] * s[i];
            W[cnt] = w[i] * s[i];
        }
    }
    for(int i = 1; i <= cnt; i++) 
        for(int j = m; j >= V[i]; j--) 
            dp[j] = max(dp[j], dp[j - V[i]] + W[i]);
            
    cout << dp[m];
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> v[i] >> w[i] >> s[i];

    // solve1();

    solve2();
    return 0;
}