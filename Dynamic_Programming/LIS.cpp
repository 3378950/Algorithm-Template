#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
const int N = 1010;
int a[N], dp[N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    for (int i = 1; i <= n; i++) {
        dp[i] = 1;
        for (int j = 1; j < i; j++) {
            if(a[i] > a[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++)
        res = max(res, dp[i]);
    printf("%d", res);
    return 0;
}