#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

void solve(){
    int dp[10001];
    int coin[21];
    
    memset(dp, 0, 10001*4);
    memset(coin, 0, 21*4);
    
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i++){
        cin >> coin[i];
    }
    
    int m;
    cin >> m;
    
    dp[0] = 1;
    
    for (int i = 1; i <= n; i++){
        for(int j = coin[i]; j <= m; j++){
            dp[j] += dp[j-coin[i]];
        }
    }
    
    printf("%d\n", dp[m]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int T;
    cin >> T;
    while (T--){
        solve();
    }
    
    return 0;
}
