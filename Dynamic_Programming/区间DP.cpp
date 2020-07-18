/*
Acwing 282. 石子合并
*/

#include <iostream>
#include <algorithm>

using namespace std;
const int N = 310;
int a[N], s[N], dp[N][N];

int main() {
    int n; cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    // 枚举区间长度
    for(int len = 2; len <= n; len++) {
        // 确定左右端点
        for(int i = 1; i + len - 1 <= n; i++) {
            int l = i, r = i + len - 1;
            dp[l][r] = 1e9;
            // 枚举决策点
            for(int k = l; k < r; k++)
                dp[l][r] = min (
                    dp[l][r], 
                    dp[l][k] + dp[k + 1][r] + s[r] - s[l - 1]
                );
        }
    }
    cout << dp[1][n];
    return 0;
}