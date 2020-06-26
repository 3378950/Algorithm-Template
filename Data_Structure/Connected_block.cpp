#include <cstdio>
#include <iostream>

using namespace std;
const int N = 1e5 + 10;
int son[N], siz[N], a[N];

int getfa(int x) {
    return son[x] = (son[x] == x)? x: getfa(son[x]);
}

int main() {
    int n, m; scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) son[i] = i, siz[i] = 1;
    while(m--) {
        string op; cin >> op;
    
        if(op == "C") {
            int a, b; scanf("%d%d", &a, &b);
            a = getfa(a), b = getfa(b);
            if(a != b) {
                son[a] = b;
                siz[b] += siz[a];
            }
            
        }
        else if(op == "Q1") {
            int a, b; scanf("%d%d", &a, &b);
            a = getfa(a), b = getfa(b);
            if(a == b) puts("Yes");
            else puts("No");
        } else {
            int a; scanf("%d", &a);
            cout << siz[getfa(a)] << endl;
        }
    }
    return 0;
}