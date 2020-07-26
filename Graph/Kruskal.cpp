#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10, M = 2e5 + 10, INF = 0x3f3f3f3f;
int n, m, fa[N];

struct edge {
    int a, b, w;
    bool operator < (const edge & T) const {
        return w < T.w;
    }
}edges[M];

int getfa(int x) {
    return fa[x] = (fa[x] == x) ? x : getfa(fa[x]);
}

int kruskal() {
    sort(edges, edges + m);
    int ans = 0, cnt = 0;
    for(int i = 0; i < m; i++) {
        int a = edges[i].a, b =  edges[i].b, c = edges[i].w;
        a = getfa(a), b = getfa(b);
        if(a != b) {
            fa[a] = b;
            cnt++;
            ans += c;
        }
    }
    if(cnt < n - 1) return INF;
    return ans;
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) fa[i] = i;
    for(int i = 0; i < m; i++) {
        int a, b, c; scanf("%d%d%d", &a, &b, &c);
        edges[i] = {a, b, c};
    }

    int t = kruskal();
    if(t == INF) puts("impossible");
    else printf("%d", t);
    return 0;
}

