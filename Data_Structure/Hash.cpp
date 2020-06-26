#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1e6 + 10, M = 100003;
int e[N], ne[N], h[N], idx;

void add(int x) {
    int p = (x % M + M) % M;
    e[idx] = x;
    ne[idx] = h[p];
    h[p] = idx++;
}

bool query(int x) {
    int p = (x % M + M) % M;
    for(int i = h[p]; ~i; i = ne[i]) {
        if(e[i] == x) return true;
    }
    return false;
}

int main() {
    int n; scanf("%d", &n);
    memset(h, -1, sizeof h);
    while(n--) {
        char op[2];
        int x;
        scanf("%s%d", op, &x);
        if(*op == 'I') add(x);
        else if(*op == 'Q') {
            if(query(x)) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}

