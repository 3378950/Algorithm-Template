#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
const int N = 110, INF = -1e9;
int mp[N][N], dp[N][N];


int main() {
    int T; scanf("%d", &T);
    while(T--) {
        int n, c;
        scanf("%d%d", &n, &c);

        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= c; j++) 
                scanf("%d", &mp[i][j]);
            
        for(int i = 0; i <= n; i++) 
            for(int j = 0; j <= c; j++) 
                dp[i][j] = INF;
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= c; j++)
                if(i == 1 && j == 1) dp[i][j] = mp[i][j];
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + mp[i][j];
        }
        
        printf("%d\n", dp[n][c]);
    }
    
    return 0;
}