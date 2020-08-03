#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;
typedef pair<int, string> PIS;

string ed = "12345678x";
unordered_map<string, pair<string, char>> pre;
unordered_map<string, int> dist;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
char op[4] = {'u', 'r', 'd', 'l'};


int fn(string s) {
    int res = 0;
    for(int i = 0; i < 9; i++)
        if(s[i] != 'x') {
            int pos = s[i] - '1';
            res += abs(i / 3 - pos / 3) + abs((i % 3) - pos % 3);
        }
    return res;
}

string bfs(string start) {
    priority_queue<PIS, vector<PIS>, greater<PIS>> hp;
    dist[start] = 0;
    hp.push({fn(start), start});
    while(!hp.empty()) {
        PIS t = hp.top(); hp.pop();
        string state = t.second;
        if(state == ed) break;
        int step = dist[state];
        int x, y;
        for (int i = 0; i < state.size(); i ++ )
            if (state[i] == 'x')
            {
                x = i / 3, y = i % 3;
                break;
            }
            
        string src = state;
        for(int i = 0; i < 4; i++) {
            int a = x + dx[i], b = y + dy[i];
            
            if(a < 0 || a >= 3 || b < 0 || b >= 3) continue;
            
            swap(state[x * 3 + y], state[a * 3 + b]);
            
            if(!dist.count(state) || dist[state] > step + 1) {
                dist[state] = step + 1;
                pre[state] = {src, op[i]};
                hp.push({dist[state] + fn(state), state});
            }
            
            swap(state[x * 3 + y], state[a * 3 + b]);
        }
    }
    string order;
    while(ed != start) {
        order += pre[ed].second;
        ed = pre[ed].first;
    }
    reverse(order.begin(), order.end());
    return order;
}

int main() {
    
    string start;
    char c;
    while(cin >> c) start += c;
    
    int eo = 0;
    for(int i = 0; i < 9; i++) 
        for(int j = i + 1; j < 9; j++)
            if(start[i] != 'x')
                if(start[i] > start[j]) 
                    eo++;
    
    if(eo & 1) puts("unsolvable");
    else cout << bfs(start) << endl;
    
    return 0;
}
