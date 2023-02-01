#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

/*
dp[i][j][k] : i길이 j인접비트 k로 끝남

dp[i][j][0] = dp[i-1][j+1][1] + dp[i-1][j][0];
dp[i][j][1] = dp[i-1][j-1][1] + dp[i-1][j][0];
*/

int dp[101][101][2];

int main(){    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    dp[2][0][0] = 2;
    dp[2][0][1] = 1;
    dp[2][1][1] = 1;
    for (int i = 3; i <= 100; i++){
        for (int j = 0; j <= 100; j++){
            dp[i][j][0] = dp[i-1][j][0];
            if (j != 100) dp[i][j][0] += dp[i-1][j][1];
            
            dp[i][j][1] = dp[i-1][j][0];
            if (j != 0) dp[i][j][1] += dp[i-1][j-1][1];
        }
    }

    int T;
    cin >> T;
    
    for (int i = 0; i < T; i++){
        int n, k;
        cin >> n >> k;
        cout << dp[n][k][0] + dp[n][k][1] << endl;
    }
    
    return 0;
}
