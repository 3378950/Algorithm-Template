#include <cstdio>

typedef long long LL;

const int N = 1e6 + 50;
int a[N], p[N];

LL merge(int l, int r) {
    if(l >= r)
        return 0;
    int mid = l + r >> 1;
    LL ans = merge(l, mid) + merge(mid + 1, r);

    int k = 0, i = l, j = mid + 1;
    while(i <= mid && j <= r) {
        if(a[i] <= a[j])
            p[k++] = a[i++];
        else {
            p[k++] = a[j++];
            ans += mid - i + 1;
        }
    }
    while(i <= mid)
        p[k++] = a[i++];

    while(j <= r)
        p[k++] = a[j++];

    for (int i = l, j = 0; i <= r; i++, j++)
        a[i] = p[j];

    return ans;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("%lld", merge(0, n - 1));
    return 0;
}