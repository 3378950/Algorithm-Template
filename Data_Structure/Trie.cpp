#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int sons[N][26], cnt[N], idx;
char s[N];

void insert(char s[]) {
    int p = 0;
    for(int i = 0; s[i]; i++){
        int u = s[i] - 'a';
        if(!sons[p][u]) sons[p][u] = ++idx;
        p = sons[p][u];
    }
    ++cnt[p];
}

int query(char s[]) {
    int p = 0;
    for(int i = 0; s[i]; i++) {
        int u = s[i] - 'a';
        if(!sons[p][u]) return 0;
        p = sons[p][u];
    }
    return cnt[p];
}

int main() {
    int n; scanf("%d", &n);
    while(n--) {
        char op[2]; scanf("%s%s", op, s);
        if(*op == 'I') insert(s);
        else printf("%d\n",query(s));
    }
    return 0;
}
