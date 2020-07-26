#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

typedef pair<int, int> PII;
const int N = 1e6 + 10;
int e[N], ne[N], h[N], w[N], d[N], idx;
int n, m;
bool st[N];

void add(int a, int b, int c) {
    e[idx] = b; w[idx] = c; ne[idx] = h[a]; h[a] = idx ++;
}

int dijkstra() {
    memset(d, 0x3f3f3f3f, sizeof d);
    priority_queue<PII, vector<PII>, greater<PII>> hp;
    d[1] = 0;
    hp.push({0, 1});
    while(hp.size()) {
        auto t = hp.top(); hp.pop();
        int ver = t.second, dis = t.first;
        if(st[ver]) continue;
        st[ver] = true;
        for(int i = h[ver]; ~i; i = ne[i]) {
            int j = e[i];
            if(d[j] > dis + w[i]) {
                d[j] = dis + w[i];
                hp.push({d[j], j});
            }
        }
    }
    if(d[n] != 0x3f3f3f3f) return d[n];
    return -1;
}
int main() {
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);
    while(m--){
        int a, b, c; scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }
    printf("%d\n", dijkstra());
    return 0;
}
