#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
typedef pair<int, int> PII;
const int N = 1010;
char g[N][N];
int n, m;
int dx[] = {0, 1, 1, 1, 0, -1, -1, -1}, dy[] = {1, 1, 0, -1, -1, -1, 0, 1};
bool st[N][N];

void bfs(int a, int b) {
    queue<PII> q;
    q.push(make_pair(a, b));
    while(q.size()) {
        PII p = q.front(); q.pop();
        int x = p.first, y = p.second;
        for(int i = 0; i < 8; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if(xx >= 0 && xx < n && yy >= 0 && yy < m && g[xx][yy] == 'W' && !st[xx][yy]) {
                q.push({xx, yy});
                st[xx][yy] = true;
            }
        }
    }

}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) 
            cin >> g[i][j];

    int cnt = 0;    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(!st[i][j] && g[i][j] == 'W') {
                bfs(i, j);
                cnt++;
            }

    cout << cnt << endl;

    return 0;
}