#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 510, M = 1e6 + 10;
struct edge {
    int a, b, c;
}edges[M];
int n, m, k, d[N], backup[N];

int bellman_ford() {
    
    memset(d, 0x3f, sizeof d);
    d[1] = 0;
    for(int i = 0; i < k; i++) {
        memcpy(backup, d, sizeof d);
        for(int j = 0; j < m; j++) {
            int a = edges[j].a, b = edges[j].b, c = edges[j].c;
            d[b] = min(d[b], backup[a] + c);
        }
    }
    if(d[n] > 0x3f3f3f3f / 2) return -1;
    return d[n];
}
int main() {
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i < m; i++) {
        int a, b, c; scanf("%d%d%d", &a, &b, &c);
        edges[i] = {a, b, c};
    }
    int t = bellman_ford();
    if(t == -1) puts("impossible");
    else printf("%d\n",t);
    return 0;
}