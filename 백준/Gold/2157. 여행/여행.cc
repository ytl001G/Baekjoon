#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

// dp[i][j] : i번째 도시까지 와서 j개 도시 들름 -> 점수

int dp[301][301];

int N, M, K;
int flight[301][301];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> M >> K;
    
    for (int i = 1; i <= K; i++){
        int start, end, score;
        cin >> start >> end >> score;
        flight[start][end]= max(flight[start][end], score);
    }

    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= M; j++){
            dp[i][j] = -1;
        }
    }
    
    dp[1][1] = 0;
    int ans = 0;
    
    for (int j = 2; j <= M; j++){
        for (int k = 1; k < N; k++){
            for (int i = k+1; i <= N; i++){
                if (dp[k][j-1] != -1 && flight[k][i] > 0){
                    dp[i][j] = max(dp[i][j], dp[k][j-1] + flight[k][i]);
                }
            }
        }
    }
    
    // for (int i = 1; i <= N; i++){
    //     for (int j = 1; j <= M; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
    for (int i = 1; i <= M; i++){
        ans = max(ans, dp[N][i]);
    }
    
    cout << ans;
    
    return 0;
}