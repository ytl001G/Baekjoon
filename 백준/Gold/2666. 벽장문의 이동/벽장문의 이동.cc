#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int n, a, b, m;
int dp[21][21][21];
int order[21];

int memo(int i, int d1, int d2){
    if (i == m+1){
        return 0;
    }
    
    if (dp[i][d1][d2] != -1){
        return dp[i][d1][d2];
    }
    
    dp[i][d1][d2] = min( memo(i+1, d1, order[i]) + abs(order[i] - d2), memo(i+1, order[i], d2) + abs(order[i] - d1) );
    return dp[i][d1][d2];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> a >> b >> m;
    
    for (int i = 1; i <= m; i++){
        cin >> order[i];
    }
    
    memset(dp, -1, sizeof(dp));
    cout << memo(1, a, b);
 
    return 0;
}
