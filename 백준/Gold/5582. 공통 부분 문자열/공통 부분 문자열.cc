#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int dp[4000][4000];

int main(){    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string a, b;
    cin >> a >> b;

    int M = 0;

    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < b.size(); j++){
            if (i == 0 || j == 0){
                dp[i][j] = (a[i] == b[j]);
            } else if(a[i] == b[j]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }

            M = max(M, dp[i][j]);
        }
    }

    cout << M;

    return 0;
}