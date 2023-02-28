#include <bits/stdc++.h>
using namespace std;

// 길이 연속량 연속변수 L변수 (0자음 1모음)
long long int dp[101][3][2][2];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string s;
    cin >> s;
    s = ' ' + s;
    
    dp[0][0][0][0] = 1;
    for (int n = 1; n < s.size(); n++){
        for (int i = 1; i <= 3; i++){
            for (int l = 0; l <= 1; l++){
                if (s[n] == 'L'){
                    if (i != 3) dp[n][i][0][1] += dp[n-1][i-1][0][l];
                    dp[n][1][0][1] += dp[n-1][i-1][1][l];
                } else if (s[n] == '_'){
                    if (i != 3) dp[n][i][1][l] += dp[n-1][i-1][1][l]*5;
                    dp[n][1][1][l] += dp[n-1][i-1][0][l]*5;
                    if (i != 3) dp[n][i][0][l] += dp[n-1][i-1][0][l]*20;
                    dp[n][1][0][l] += dp[n-1][i-1][1][l]*20;
                    
                    // L case
                    if (i != 3) dp[n][i][0][1] += dp[n-1][i-1][0][l];
                    dp[n][1][0][1] += dp[n-1][i-1][1][l];
                } else if (s[n] == 'A' || s[n] == 'E' || s[n] == 'I' || s[n] == 'O' || s[n] == 'U'){
                    if (i != 3) dp[n][i][1][l] += dp[n-1][i-1][1][l];
                    dp[n][1][1][l] += dp[n-1][i-1][0][l];
                } else {
                    if (i != 3) dp[n][i][0][l] += dp[n-1][i-1][0][l];
                    dp[n][1][0][l] += dp[n-1][i-1][1][l];
                }
            }
        }
    }
    
    long long int ans = 0;
    for (int i = 0; i <= 2; i++){
        for (int c = 0; c <= 1; c++){
            ans += dp[s.size()-1][i][c][1];
        }
    }
    
    cout << ans;
    
    return 0;
}
