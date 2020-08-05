#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 110;
char g[N][N];
int n;
int sx, sy, ex, ey; 
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
bool st[N][N];

bool dfs(int x, int y) {
    if(x == ex && y == ey) {
        return true;
    }
    
    if(g[x][y] == '#') return false;

    
    st[x][y] = true;
    
    for(int i = 0; i < 4; i++) {
        int xx = x + dx[i], yy = y + dy[i];
        if(xx < 0 || xx >= n || yy < 0 || yy >= n) continue;
        if(st[xx][yy]) continue ;
        if(dfs(xx, yy)) return true;
    }
    
    return false;
}

int main() {
    int T; 
    scanf("%d", &T);
    while(T--) {
        memset(st, false, sizeof st);
        scanf("%d", &n);
        for(int i = 0; i < n; i++) cin >> g[i];
        cin >> sx >> sy >> ex >> ey;
        
        if(g[sx][sy] == '#' || g[ex][ey] == '#') puts("NO");
        else if(dfs(sx, sy))
            puts("YES");
        else 
            puts("NO");

    }
    return 0;
}