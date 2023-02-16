#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int W[1001];
int B[1001];
int dp[1001][16][16];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int w, b;
    int n = 1;
    while (cin >> w >> b){
        W[n] = w;
        B[n] = b;
        n++;
    }
    
    memset(dp, -1, sizeof(dp));
    
    dp[0][0][0] = 0;
    int ans = 0;
    for (int i = 1; i < n; i++){
        for (int j = 0; j <= 15; j++){
            for (int k = 0; k <= 15; k++){
                dp[i][j][k] = dp[i-1][j][k];
                if (j >= 1){
                    dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-1][k] + W[i]);
                }
                if (k >= 1){
                    dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k-1] + B[i]);
                }
                
                if (j == 15 && k == 15){
                    ans = max(ans, dp[i][j][k]);
                }
            }
        }
    }
    
    cout << ans;

    return 0;
}
