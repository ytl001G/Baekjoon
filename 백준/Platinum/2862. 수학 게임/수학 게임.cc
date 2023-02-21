#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

vector<long long int> dp;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    long long int n;
    cin >> n;
    
    long long int a=1, b=1;
    
    while (b <= n){
        dp.push_back(b);
        
        long long int temp = b;
        b += a;
        a = temp;
    }
    
    long long int ans = -1;
    for(int i = dp.size()-1; i >= 0; i--){
        if (n >= dp[i]){
            n -= dp[i];
            ans = dp[i];
        }
    }
    
    cout << ans;

    return 0;
}
