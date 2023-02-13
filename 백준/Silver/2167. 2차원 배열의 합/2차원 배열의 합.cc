#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int n, m;
int arr[301][301];
int dp[301][301];

void solve(){
    int i,j,x,y;
    cin >> i >> j >> x >> y;
    printf("%d\n", dp[x][y] - dp[x][j-1] - dp[i-1][y] + dp[i-1][j-1]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            dp[i][j] = arr[i][j] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
        }
    }
    
    int k;
    cin >> k;
    while (k--){
        solve();
    }
    
    return 0;
}
