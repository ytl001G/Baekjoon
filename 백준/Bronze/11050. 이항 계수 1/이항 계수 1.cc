#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll dp[11];

ll fact(ll n){
    if (n == 1 || n == 0) return 1;
    if (dp[n]) return dp[n];
    ll& ans = dp[n];
    ans = n * fact(n-1);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    ll n, k;
    cin >> n >> k;
    cout << fact(n) / fact(n-k) / fact(k);

    return 0;
}