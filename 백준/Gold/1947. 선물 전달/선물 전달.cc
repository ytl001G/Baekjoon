#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int n;
long long int dp[1000001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    dp[1] = 0;
    dp[2] = 1;
    
    cin >> n;
    for (int i = 3; i <= n; i++){
        dp[i] = (i-1) * (dp[i-1] + dp[i-2]) % 1000000000;
    }
    
    cout << dp[n];
    
    return 0;
}
