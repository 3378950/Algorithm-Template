<font size=4>



## Quick_Sort and Merge_Sort
### Quick_Sort： 由小到大排序
#### 算法思路： 
* 确定一个分界点x, 设置两个指针i、j, i从下标0到x的下标处从前到后遍历， j由下标n - 1,到x的下标处由后到前遍历。
* 当i所指的数比x大，此时i指针停止。
* 当j所指的数比x小，此时j指针停止。
* 交换i、j所指的数。
* 继续进行i、j的操作，最终使得x左边的数都比x小，x右边的数都比x大。
* 递归进行以上操作


#### 代码
```c++
void quick_sort(int a[],int l,int r) {
    if(l >= r) return ;
    // 确定分界点、i、j指针
    int x = a[(l + r) / 2], i = l - 1, j = r + 1;
    while(i < j) {
        do i++; while(a[i] < x);
        do j--; while(a[j] > x);
        if(i < j) swap(a[i],a[j]); // 交换两者
    }
    // 递归
    quick_sort(a,l,j);
    quick_sort(a,j+1,r);
}
```

### Merge_Sort： 由小到大排序
#### 算法思路：
* 对数组进行划分
* 合并


#### 代码
```c++
void merge_sort(int a[], int l, int r) {
    if(l >= r) return;
    // divide
    int mid = l + r >> 1;
    merge_sort(a, l, mid); merge_sort(a, mid + 1, r);

    int k = 0, i = l, j = mid + 1;
    while(i <= mid && j <= r) {
        if(a[i] < a[j]) tmp[k++] = a[i++];
        else tmp[k++] = a[j++];
    }
    while(i <= mid) tmp[k++] = a[i++];
    while(j <= r) tmp[k++] = a[j++];
    // merge
    for(int i = l, j = 0; i <= r; i++, j++) a[i] = tmp[j];
}
```
### 完整代码
```c++
#include <iostream>

using namespace std;

const int N = 1e6 + 10;
int a[N], t[N];

void quick_sort(int a[],int l,int r) {
    if(l >= r) return ;
    
    int x = a[(l + r) / 2], i = l - 1, j = r + 1;
    while(i < j) {
        do i++; while(a[i] < x);
        do j--; while(a[j] > x);
        if(i < j) swap(a[i],a[j]);
    }
    quick_sort(a,l,j);
    quick_sort(a,j+1,r);
}

void merge(int a[], int l, int r) {
    if(l >= r) return ;
    int mid = l + r >> 1;
    merge(a, l, mid); merge(a, mid + 1, r);
    int k = 0, i = l, j = mid + 1;
    while(i <= mid && j <= r) {
        if(a[i] < a[j]) t[k++] =  a[i++];
        else t[k++] = a[j++];
    }
    while(i <= mid) t[k++] = a[i++];
    while(j <= r) t[k++] = a[j++];
    
    for(int i = l, j = 0; i <= r; i++, j++) a[i] = t[j];
    
}

int main() {
    int n; scanf("%d",&n);
    for(int i = 0; i < n; i++) scanf("%d",&a[i]);
    // quick_sort(a, 0, n - 1);
    merge(a, 0, n - 1);
    for(int i = 0; i < n; i++) printf("%d ",a[i]);
    return 0;
    
}
```
</font>