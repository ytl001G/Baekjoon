#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int box[1001];
int dp[1001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i++){
        cin >> box[i];
    }
    
    for (int i = 1; i <= n; i++){
        dp[i] = 1;
        for (int j = 1; j <= i; j++){
            if (box[i] > box[j]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    
    int ans = 0;
    for (int i = 1; i <= n; i++){
        ans = max(ans, dp[i]);
    }
    
    cout << ans;
    
    return 0;
}
