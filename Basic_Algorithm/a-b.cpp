#include <iostream>
#include <vector>

using namespace std;

bool cmp(vector<int> x, vector<int> y) {
    if(x.size() != y.size()) return x.size() > y.size();
    for(int i = x.size() - 1; i >= 0; i--) {
        if(x[i] != y[i]) return x[i] > y[i];
    }
    return true;
}

vector<int> sub(vector<int> x, vector<int> y) {
    vector<int> res;
    int t = 0;
    for(int i = 0; i < x.size(); i++) {
        t = x[i] - t;
        if(i < y.size()) t -= y[i];
        res.push_back((t + 10) % 10);
        t = (t < 0) ? 1: 0;
    }
    while(res.back() == 0 && res.size() > 1) res.pop_back();
    return res;
}
int main() {
    vector<int> x, y, r;
    string a, b; cin >> a >> b;
    for(int i = a.length() - 1; i >= 0; i--) x.push_back(a[i] - '0');
    for(int i = b.length() - 1; i >= 0; i--) y.push_back(b[i] - '0');
    
    if(cmp(x, y)) r = sub(x, y);
    else {
        r = sub(y, x);
        printf("-");
    }
    for(int i = r.size() - 1; i >= 0; i--) printf("%d", r[i]);
    return 0;
}