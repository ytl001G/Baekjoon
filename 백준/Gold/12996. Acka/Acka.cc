#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

long long int dp[51][51][51][51];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int s, a, b, c;
    cin >> s >> a >> b >> c;
    
    dp[0][0][0][0] = 1;
    for (int n = 1; n <= s; n++){
        for (int i = 0; i <= a; i++){
            for (int j = 0; j <= b; j++){
                for (int k = 0; k <= c; k++){

                    for (int ii = 0; ii <= 1; ii++){
                        for (int jj = 0; jj <= 1; jj++){
                            for (int kk = 0; kk <= 1; kk++){
                                if ((!i && ii) || (!j && jj) || (!k && kk)) continue;
                                if (!ii && !jj && !kk) continue;
                                dp[n][i][j][k] += dp[n-1][i-ii][j-jj][k-kk];
                            }   
                        }
                    }
                    
                    dp[n][i][j][k] %= 1000000007;
                }
            }
        }
    }
    
    cout << dp[s][a][b][c];

    return 0;
}
