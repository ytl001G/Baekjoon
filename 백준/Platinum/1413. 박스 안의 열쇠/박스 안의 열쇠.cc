#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

long long int dp[21][21];

long long int gcd(long long int a, long long int b){
    if (b == 0){
        return a;
    }
    return gcd(b,a%b);
}

long long int fact(long long int n){
    if (n == 1){
        return 1;
    }
    return n * fact(n-1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    dp[1][1] = 1;
    for (int i = 2; i <= n; i++){
        for (int j = 1; j <= m; j++){
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j] * (i-1);
        }
    }

    long long int ans = 0;
    for (int i = 1; i <= m; i++){
        ans += dp[n][i];
    }
    
    long long int ans1 = fact(n);
    
    long long int g = gcd(ans, ans1);

    printf("%lld/%lld", ans/g, ans1/g);
    
    return 0;
}
