#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

// dp[i][j] : 1번이 i, 2번이 j에 있음

int dp[1001][1001];
string square[1001];

int n, m;

int memo(int i, int j){
    if (i == n || j == m){
        dp[i][j] = square[i][j] - '0';
        return dp[i][j];
    }
    
    if (dp[i][j] != -1){
        return dp[i][j];
    }
    
    int rbound = memo(i+1, j+1) + 1, ubound = memo(i+1, j+1) + 1;
    bool rconti = true, uconti = true;
    
    for (int k = 0; k <= dp[i+1][j+1]; k++){
        if (square[i][j+k] == '0' && rconti){
            rconti = false;
            rbound = k;
        }
        if (square[i+k][j] == '0' && uconti){
            uconti = false;
            ubound = k;
        }
    }
    
    dp[i][j] = min(rbound, ubound);
    return dp[i][j];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++){
        cin >> square[i];
        square[i] = " " + square[i];
    }
    
    for (int i = 1; i <= n; i++){
        for ( int j = 1; j <= m; j++){
            dp[i][j] = -1;
        }
    }
    
    for (int i = 1; i <= n; i++){
        memo(i, 1);
    }
    for (int j = 1; j <= m; j++){
        memo(1, j);
    }
    
    int ans = 0;
    for (int i = 1; i <= n; i++){
        for ( int j = 1; j <= m; j++){
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans*ans;
    
    return 0;
}