#include <bits/stdc++.h>
using namespace std;

// n번째 원인데 빨간색을 r개 씀!
int dp[1001][50001];

const int mod = 1000000007;

void solve(){
    int a, b;
    cin >> a >> b;
    
    dp[0][0] = 1;
    
    int m = 0;
    while (m * (m+1) / 2 < a+b){
        m++;
    }
    
    int ans = 0;
    for (int n = 1; n <= m; n++){
        for (int r = 0; r <= a; r++){
            if (n * (n+1) / 2 - r > b) continue;
            
            dp[n][r] = dp[n-1][r];
            if (r-n >= 0){
                dp[n][r] += dp[n-1][r-n];
            }
            dp[n][r] %= mod;
            
            ans += dp[n][r];
            ans %= mod;
        }
    }
    
    printf("%d\n", ans);
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
