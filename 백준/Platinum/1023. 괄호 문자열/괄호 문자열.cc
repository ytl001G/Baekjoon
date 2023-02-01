#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

/*
dp[i][j] : i길이 j개 짝이 맞지 않는 (

*/

long long int dp[51][51];

int main(){    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    long long int k;
    cin >> n >> k;

    dp[0][0] = 1;
    

    for(int i = 1; i <= n; i++){
        dp[i][0] = dp[i-1][1];
        for(int j = 1; j <= n; j++){
            dp[i][j] = dp[i-1][j-1];
            if (j+1 <= n){
                dp[i][j] += dp[i-1][j+1];
            }
        }
    }
    
    long long int total = 1LL << n;
    if (k >= total - dp[n][0]){
        cout << -1;
        return 0;
    }

    int open = 0;
    for(int len = n; len >= 1; len--){
        long long int left = 1LL << (len - 1);

        if (open >= 0){
            left -= dp[len-1][open+1];
        }

        if (k < left){
            cout << '(';
            open += 1;
        } else {
            cout << ')';
            open -= 1;
            k -= left;
            
            if (open < 0){
                open = -1000000;
            }
        }
    }

    return 0;
}
