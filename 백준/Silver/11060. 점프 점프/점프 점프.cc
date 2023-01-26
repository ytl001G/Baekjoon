#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int dp[1000], A[1000];

int main(){    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> A[i];
    }

    for (int i = 0; i < n; i++){
        if(i != 0 && dp[i] == 0){
            continue;
        }

        for(int j = 1; j <= A[i]; j++){
            if(i+j >= 1000){
                break;
            }

            if(dp[i+j] > 0){
                dp[i+j] = min(dp[i+j], dp[i]+1);
            } else {
                dp[i+j] = dp[i]+1;
            }
        }
    }

    if(dp[n-1] || n == 1){
        cout << dp[n-1];
    } else {
        cout << -1;
    }

    return 0;
}