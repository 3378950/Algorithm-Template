#include <iostream>

using namespace std;
typedef unsigned long long ULL;
const int N = 1e5 + 10, P = 131;
ULL h[N], p[N];
char s[N];

ULL check(int l, int r) {
    return h[r] - h[l - 1] * p[r - l + 1];
}

int main() {
    int n, m; scanf("%d%d", &n, &m);
    cin >> s + 1;
    p[0] = 1;
    for(int i = 1; i <= n; i++) {
        p[i] = p[i - 1] * P;
        h[i] = h[i - 1] * P + s[i];
    }
    while(m--) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        if(check(a, b) == check(c, d)) puts("Yes");
        else puts("No");
    }
    return 0;
}