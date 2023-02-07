#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

// dp[i][j][k] : 두루마리 i번 글자까지 j번째 돌 k쪽 돌다리(0,1)

int dp[20][100][2];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    string spell, E, D;
    
    cin >> spell >> E >> D;
    
    int ans = 0;
    
    for (int i = 0; i < spell.size(); i++){
        for (int j = 0; j < E.size(); j++){
            if (i == 0){
                if (spell[0] == E[j])
                    dp[i][j][0] = 1;
                
                if (spell[0] == D[j])
                    dp[i][j][1] = 1;
            } else {
                for (int k = j-1; k >= 0; k--){
                    if (spell[i-1] == D[k] && spell[i] == E[j])
                        dp[i][j][0] += dp[i-1][k][1];
    
                    if (spell[i-1] == E[k] && spell[i] == D[j])
                        dp[i][j][1] += dp[i-1][k][0];
                }
            }
            
            if (i == spell.size()-1){
                ans += dp[i][j][0] + dp[i][j][1];
            }
        }
    }
    
    // for (int i = 0; i < spell.size(); i++){
    //     for (int j = 0; j < E.size(); j++){
    //         cout << dp[i][j][0] << " ";
    //     }
    //     cout << endl;
    // }
    
    // cout << endl;
    
    // for (int i = 0; i < spell.size(); i++){
    //     for (int j = 0; j < E.size(); j++){
    //         cout << dp[i][j][1] << " ";
    //     }
    //     cout << endl;
    // }
    
    cout << ans;
    
    return 0;
}