#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

long long int dp[10001];

int main(){    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    dp[0] = 1;
    
    int n;
    cin >> n;
    
    for(int i = 2; i <= n; i += 2){
        for(int k = 0; k < i; k += 2){
            dp[i] += dp[i-k-2]*dp[k];
            dp[i] %= 987654321;
        }
    }
    
    cout << dp[n] % 987654321;
    
    return 0;
}
