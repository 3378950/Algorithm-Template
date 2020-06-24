#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> x, y, r;
    string a, b; cin >> a >> b;
    for(int i = a.length() - 1; i >= 0; i--) x.push_back(a[i] - '0');
    for(int i = b.length() - 1; i >= 0; i--) y.push_back(b[i] - '0');

    int t = 0;
    for(int i = 0; i < x.size() || i < y.size(); i++) {
        if(i < x.size()) t += x[i];
        if(i < y.size()) t += y[i];
        r.push_back(t % 10);
        t /= 10;
    }
    if(t) r.push_back(1);
    
    for(int i = r.size() - 1; i >= 0; i--) printf("%d", r[i]);
    return 0;
}