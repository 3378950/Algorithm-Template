#include <iostream>
#include <cstring>
#include <unordered_map>
#include <queue>

using namespace std;

int bfs(string start) {
    int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
    string end = "12345678x";
    unordered_map<string, int> mp;
    mp[start] = 0;
    queue<string> q;
    q.push(start);
    while(q.size()) {
        string t = q.front(); q.pop();
        int dist = mp[t];
        if(t == end) return mp[end];
        
        int k = t.find('x');
        int x = k / 3, y = k % 3;
        for(int i = 0; i < 4; i++) {
            int cx = x + dx[i], cy = y + dy[i];
            if(cx < 0 || cx >= 3 || cy < 0 || cy >= 3) continue;
            swap(t[k], t[cx * 3 + cy]);
            
            if(!mp.count(t)) {
                mp[t] = dist + 1;
                q.push(t);
            }
            
            swap(t[k], t[cx * 3 + cy]);
        }
    }
    
    return -1;
}

int main() {
    string start;
    char c;
    for(int i = 0; i < 9; i++) {
        cin >> c;
        start += c;
    }
    
    cout << bfs(start) << endl;
    return 0;
}