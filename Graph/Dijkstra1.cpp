#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 510;
int g[N][N], d[N];
bool st[N];
int n, m;

int dijkstra() {
    memset(d, 0x3f3f3f3f, sizeof d);
    d[1] = 0;
    for(int i = 0; i < n; i++) {
        int t = -1;
        for(int j = 1; j <= n; j++) {
            if(!st[j] && (t == -1 || d[j] < d[t])) t = j;
        }
        st[t] = true;
        for(int j = 1; j <= n; j++) {
            d[j] = min(d[j], d[t] + g[t][j]);
        }
    }
    if(d[n] != 0x3f3f3f3f) return d[n];
    return -1;
}

int main() {
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);
    while(m--) {
        int a, b, c; cin >> a >> b >> c;
        g[a][b] = min(g[a][b], c);
    }
    cout << dijkstra();
}