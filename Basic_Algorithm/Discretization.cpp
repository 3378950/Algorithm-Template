#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 3e5 + 10;
int a[N], s[N];
typedef pair<int, int> PII;
vector<int> alls;
vector<PII> query, add;

// discrete
int find(int x) {
    int l = 0, r = alls.size() - 1;
    while(l < r) {
        int mid = (l + r) >> 1;
        if(alls[mid] >= x)
            r = mid;
        else
            l = mid + 1;
    }
    return r + 1;
}

int main() {
    int n, m; scanf("%d%d", &n, &m);
    int x, c;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &x, &c);
        add.push_back({x, c});
        alls.push_back(x);
    }

    for (int i = 0; i < m; i++) {
        int l, r; scanf("%d%d", &l, &r);
        query.push_back({l, r});
        alls.push_back(l); alls.push_back(r);
    }

    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());

    for(auto item: add) {
        int x = find(item.first);
        a[x] += item.second;
    }

    for (int i = 1; i <= alls.size(); i++)
        s[i] = s[i - 1] + a[i];

    for (auto q : query)
    {
        int l = find(q.first), r = find(q.second);
        printf("%d", s[r] - s[l - 1]);
    }
    return 0;
}

