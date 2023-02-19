#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

// p번째까지 n곡 듣는경우
long long int dp[105][105];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m, p;
    cin >> n >> m >> p;
    
    dp[1][1] = n;
    
    for (int i = 1; i <= p; i++){
        for (int j = 1; j <= n; j++){
            dp[i+1][j+1] += dp[i][j] * (n-j);
            dp[i+1][j+1] %= 1000000007;
            
            if (j > m){
                dp[i+1][j] += dp[i][j] * (j-m);
                dp[i+1][j] %= 1000000007;
            }
        }
    }
    
    cout << dp[p][n] << endl;
    
    // for (int i = 1; i <= p; i++){
    //     for (int j = 1; j <= n; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}
