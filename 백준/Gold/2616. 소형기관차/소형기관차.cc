#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

/*
dp[i][j] : 소형 i개로 객차 j개
*/

int train[50001], sum[50001], dp[4][50001];

int main(){    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> train[i];
        sum[i] = sum[i-1] + train[i];
    }

    cin >> m;

    for(int i = 1; i <= 3; i++){
        for(int j = i*m; j <= n; j++){
            dp[i][j] = max(dp[i-1][j-m] + sum[j] - sum[j-m], dp[i][j-1]);
        }
    }

    cout << dp[3][n];

    return 0;
}