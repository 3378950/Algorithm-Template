#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 6010;
int e[N], ne[N], h[N], idx;
int dp[N][2], ha[N];
int n;
bool has_fa[N];

void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

void dfs(int u) {
    dp[u][1] += ha[u];
    for(int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        
        dfs(j);
        
        dp[u][0] += max(dp[j][0], dp[j][1]);
        dp[u][1] += dp[j][0];
    }
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> ha[i];
    
    memset(h, -1, sizeof h);
    for(int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        add(b, a);
        has_fa[a] = true;
    }
    int p = 1;
    while(has_fa[p]) p++;
    dfs(p);
    cout << max(dp[p][0], dp[p][1]);
    return 0;
}