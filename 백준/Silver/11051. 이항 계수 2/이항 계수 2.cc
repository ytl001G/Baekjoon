#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int n, k;
int dp[1001][1001];

int com(int i, int j){
    if (j == 0 || i == j){
        return 1;
    }
    
    if (dp[i][j]){
        return dp[i][j];
    }

    dp[i][j] = (com(i-1, j-1) + com(i-1, j))%10007;
    return dp[i][j];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> k;
    
    cout << com(n, k);
 
    return 0;
}
