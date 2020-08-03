#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
const int N = 1010, M = N * N;
int e[M], w[M], ne[M], h[N], rh[N], idx;
bool st[N];
int dist[N];
int S, T, K;

void add(int h[], int a, int b, int c) {
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}

/*
使用dijkstra逆向求最短距离，以此当做估计函数
*/
void Dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    priority_queue<PII, vector<PII>, greater<PII>> hp;
    hp.push({0, T});
    dist[T] = 0;
    while(hp.size()) {
        PII t = hp.top(); hp.pop();
        int ver = t.second, distance = t.first;
        if(st[ver]) continue;
        st[ver] = true;
        for(int i = rh[ver]; ~i; i = ne[i]) {
            int j = e[i];
            if(dist[j] > dist[ver] + w[i]) {
                dist[j] = dist[ver] + w[i];
                hp.push({dist[j], j});
            }
        }
    }
}

int Astar() {
    // 该图是不连通的
    if(dist[S] == 0x3f3f3f3f) return -1;
    
    int cnt = 0;
    priority_queue<PIII, vector<PIII>, greater<PIII>> ahp;
    ahp.push({dist[S], {0, S}});
    while(ahp.size()) {
        PIII t = ahp.top(); ahp.pop();
        int ver = t.second.second;
        int distance = t.second.first;
        if(ver == T) cnt++;
        if(cnt == K) return distance;
        
        for(int i = h[ver]; ~i; i = ne[i]) {
            int j = e[i];
            ahp.push({distance + w[i] + dist[j], {distance + w[i], j}});
        }
    }
    return -1;
}

int main() {
    int n, m; cin >> n >> m;
    memset(h, -1, sizeof h);
    memset(rh, -1, sizeof rh);
    for(int i = 0; i < m; i++) {
        int a, b, c; scanf("%d%d%d", &a, &b, &c);
        add(h, a, b, c);
        add(rh, b, a, c);
    }
    scanf("%d%d%d", &S, &T, &K);
    if(S == T) K++;
    Dijkstra();
    printf("%d\n", Astar());
    return 0;
}