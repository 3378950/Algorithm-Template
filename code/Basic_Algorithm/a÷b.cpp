#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> x, ans;
    string a; int b; 
    cin >> a >> b;
    for(int i = a.length() - 1; i >= 0; i--) x.push_back(a[i] - '0');
    int r = 0;
    for(int i = x.size() - 1; i >= 0; i--) {
        r = r * 10 + x[i];
        ans.push_back(r / b);
        r %= b;
    }
    reverse(ans.begin(), ans.end());
    while(ans.back() == 0 && ans.size() > 1) ans.pop_back();
    for(int i = ans.size() - 1; i >= 0; i--) printf("%d", ans[i]);
    cout << endl << r;
    return 0;
}