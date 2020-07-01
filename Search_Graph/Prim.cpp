#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 510, INF = 0x3f3f3f3f;
int g[N][N], d[N];
bool st[N];
int n, m;

int prim() {
    int ans = 0;
    memset(d, INF, sizeof d);
    for(int i = 0; i < n; i++) {
        int t = -1;
        for(int j = 1; j <= n; j++) {
            if(!st[j] && (t == -1 || d[t] > d[j])) t = j;
        }
        if(i && d[t] == INF) return INF;
       
        if(i) ans += d[t];
        st[t] = true;
        
        for(int j = 1; j <= n; j++) {
            d[j] = min(d[j], g[t][j]);
        } 
        
    }
    return ans;
}

int main() {
    cin >> n >> m;
    memset(g, INF, sizeof g);
    while(m--) {
        int a, b, c; cin >> a >> b >> c;
        g[a][b] = g[b][a] = min(g[a][b], c);
    }
    int t = prim();
    if(t == INF) puts("impossible");
    else cout << t << endl;
    return 0;
}