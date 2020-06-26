#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e6 + 10;
int h[N],n,m,siz;

void down(int u) {
    int t = u;
    if(u * 2 <= siz && h[u * 2] < h[t]) t = u * 2;
    if(u * 2 + 1 <= siz && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
    if(t != u) {
        swap(h[t], h[u]);
        down(t);
    }
}

int main() {
    scanf("%d%d",&n,&m);
    for(int i = 1; i <= n; i++) scanf("%d",&h[i]);
    siz = n;
    for(int i = n / 2; i; i--) down(i);
    while(m--) {
        printf("%d ",h[1]);
        h[1] = h[siz];
        siz--;
        down(1);
    }
    return 0;
}
