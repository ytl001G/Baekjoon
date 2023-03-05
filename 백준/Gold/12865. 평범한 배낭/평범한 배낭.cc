#include <bits/stdc++.h>
using namespace std;

int dp[101][100001];
int s[101][2];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    
    for (int i = 1; i <= n; i++){
        cin >> s[i][0] >> s[i][1];
    }
    
    
    
    memset(dp, -1, sizeof(dp));
    
    dp[0][0] = 0;
    
    int ans = 0;
    
    for (int i = 1; i <= n; i++){
        for (int j = k; j >= 0; j--){
            dp[i][j] = dp[i-1][j];
            
            if (j - s[i][0] >= 0 && dp[i-1][j - s[i][0]] != -1){
                dp[i][j] = max(dp[i][j], dp[i-1][j - s[i][0]] + s[i][1]);
            }
            
            if (i == n){
                ans = max(ans, dp[i][j]);
            }
        }
    }
    
    cout << ans;

    return 0;
}
