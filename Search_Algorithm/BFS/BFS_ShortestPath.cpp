#include <iostream>
#include <cstring>

using namespace std;
typedef pair<int, int> PII;
const int N = 160, M = N * N;
char g[N][N];
int n, m, dist[N][N];
PII st, q[M];
int dx[] = {-1, -2, -2, -1, 1, 2, 2, 1}, dy[] = {2, 1, -1, -2, -2, -1, 1, 2};

int bfs() {
    memset(dist, -1, sizeof dist);
    int sx = st.first, sy = st.second;
    int tt = -1, hh = 0;
    q[++tt] = {sx, sy};
    dist[sx][sy] = 0;
    while(hh <= tt) {
        PII t = q[hh++];
        int tx = t.first, ty = t.second;
        for(int i = 0; i < 8; i++) {
            int xx = tx + dx[i], yy = ty + dy[i];
            if(xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
            if(g[xx][yy] == '*') continue;
            if(dist[xx][yy] != -1) continue;
            if(g[xx][yy] == 'H') return dist[tx][ty] + 1;
            q[++tt] = {xx, yy};
            dist[xx][yy] = dist[tx][ty] + 1;
        }
    }
    return -1;
}

int main() {
    scanf("%d%d", &m, &n);
    
    
    for(int i = 0; i < n; i++) cin >> g[i];
    
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < m; j++)  
            if(g[i][j] == 'K')
                st = {i, j};
    
    cout << bfs() << endl;
    
    return 0;
}
