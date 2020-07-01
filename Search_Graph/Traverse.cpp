#include <iostream>
#include <cstring>
#include <queue>

const int N = 1010;
int e[N], ne[N], h[N], idx;
int n, m;
bool st[N];

void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

void dfs(int x) {
    if(!st[x]) {
        st[x] = true;
    }
    
    for (int i = h[x]; ~i; i = ne[i]) {
        int j = e[i];
            
        if(!st[j]) {
            std::cout << j << " ";
            dfs(j);
        }
    }
}

void bfs() {
    std::queue<int> q;
    q.push(1);
    st[1] = true;

    while(q.size()) {
        int t = q.front();
        q.pop();
        for (int i = h[t]; ~i; i = ne[i]) {
            int j = e[i];
            if(!st[j]) {
                st[j] = true;
                std::cout << j << " ";
                q.push(j);
            }
        }
    }
}

int main() {
    std::cin >> n >> m;
    memset(h, -1, sizeof h);
    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        add(a, b);
    }
    bfs();
    return 0;
}