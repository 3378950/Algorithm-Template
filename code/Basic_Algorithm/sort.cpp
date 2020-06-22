#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;
int a[N], tmp[N];

void quick_sort(int a[], int l, int r) {
    if(l >= r)
        return;
    int t = a[(l + r) >> 1], i = l - 1, j = r + 1;
    while(i < j) {
        do
            i++;
        while (a[i] < t);
        do
            j--;
        while (a[j] > t);
        if(i < j)
            swap(a[i], a[j]);
    }
    quick_sort(a, l, j);
    quick_sort(a, j + 1, r);
}

void merge_sort(int a[], int l, int r) {
    if(l >= r)
        return;
    // divide
    int mid = (l + r) >> 1;
    merge_sort(a, l, mid);
    merge_sort(a, mid + 1, r);

    int k = 0, i = l, j = mid + 1;
    while(i <= mid && j <= r) {
        if(a[i] < a[j])
            tmp[k++] = a[i++];
        else
            tmp[k++] = a[j++];
    }

    while(i <= mid)
        tmp[k++] = a[i++];
    while(j <= r)
        tmp[k++] = a[j++];
    // merge
    for (int i = l, j = 0; i <= r; i++, j++)
        a[i] = tmp[j];
    
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    // quick_sort(a, 0, n - 1);
    // merge_sort(a, 0, n - 1);
    // sort(a, a + n);

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    return 0;
}