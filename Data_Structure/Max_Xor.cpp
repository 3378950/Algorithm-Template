#include <iostream>
#include <algorithm>

const int N = 1e5 + 10, M = N * 31;
int t[M][2], idx;

void build(int x) {
    int p = 0;
    for (int i = 30; ~i; i--) {
        int u = (x >> i) & 1;
        if(!t[p][u]) t[p][u] = ++idx;
        p = t[p][u];
    }
}

int query(int x) {
    int p = 0, res = 0;
    for (int i = 30; ~i; i--) {
        int u = (x >> i) & 1;
        if(t[p][!u]) {
            p = t[p][!u];
            res = res * 2 + !u;
        } else {
            p = t[p][u];
            res = res * 2 + u;
        }
    }
    return res;
}

int main() {
    int n, res = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        build(x);
        res = std::max(res, x ^ query(x));
    }
    printf("%d\n", res);
    return 0;
}
