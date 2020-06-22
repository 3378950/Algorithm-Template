#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> x, r;
    string a;
    int b; cin >> a >> b;
    for(int i = a.length() - 1; i >= 0; i--) x.push_back(a[i] - '0');
    int t = 0;
    
    for(int i = 0; i < x.size() || t; i++) {
        if(i < x.size()) t += x[i] * b;
        r.push_back(t % 10);
        t /= 10;
    }
    while(r.back() == 0 && r.size() > 1) r.pop_back();
    for(int i = r.size() - 1; i >= 0; i--) printf("%d", r[i]);
    return 0;
} 