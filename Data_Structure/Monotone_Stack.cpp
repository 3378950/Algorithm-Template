#include <cstdio>

const int N = 1e5 + 10;
int st[N], tt;

// find the nearest element smaller than it, if none print -1

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x; scanf("%d", &x);
        while(tt && st[tt] >= x) --tt;
        if(tt) printf("%d ", st[tt]);
        else printf("-1 ");
        st[++tt] = x;
    }
    return 0;
}