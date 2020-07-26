#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
const int N = 1e6 + 40;
int e[N], ne[N], h[N], w[N], idx;
int d[N], n, m;
bool st[N];

void add(int a, int b, int c) {
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}

int spfa() {
    queue<int> q;
    memset(d, 0x3f, sizeof d);
    d[1] = 0; st[1] = true;
    q.push(1);
    while(q.size()) {
        int t = q.front(); q.pop();
        st[t] = false;
        for(int i = h[t]; ~i; i = ne[i]) {
            int j = e[i];
            if(d[j] > d[t] + w[i]) {
                d[j] = d[t] + w[i];
                if(!st[j]) {
                    st[j] = true;
                    q.push(j);
                }
            }
        }
    }
    return d[n];
}
    
int main() {
    cin >> n >> m;
    memset(h, -1, sizeof h);
    while(m--) {
        int a, b, c; cin >> a >> b >> c;
        add(a, b, c);
    }
    int t = spfa();
    if(t == 0x3f3f3f3f) puts("impossible");
    else cout << t;
    return 0;
}