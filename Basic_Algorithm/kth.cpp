#include <iostream>
#include <algorithm>

const int N = 1e6 + 10;
int a[N];

int qs(int l, int r, int k) {
    if(l >= r) return a[l];
    
    int x = a[(l + r) >> 1], i = l - 1, j = r + 1;
    while(i < j) {
        do i++; while(a[i] < x);
        do j--; while(a[j] > x);
        if(i < j) std::swap(a[i], a[j]);
    }
    int s = j - l + 1;
    if(s >= k) return qs(l, j, k);
    else return qs(j + 1, r, k - s);
} 

int main() {
    int n, k; scanf("%d%d", &n, &k);
    
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    std::cout << qs(0, n - 1, k);
    return 0;
}