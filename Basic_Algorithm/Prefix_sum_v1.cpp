#include <cstdio>

// One-dimensional
const int N = 1e6 + 10;
int a[N];

int main() {
    int n, q; scanf("%d%d", &n, &q);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for(int i = 2; i <= n; i++) a[i] += a[i - 1];
    // q times of query
    while(q--) {
        // print the sum between l and r
        int l, r; scanf("%d%d", &l, &r);
        printf("%d\n", a[r] - a[l - 1]);
    }
    return 0;
}

