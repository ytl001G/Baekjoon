
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

// dp[i][j] : 1번이 i, 2번이 j에 있음음

int dp[1005][1005];
int dist[1005][1005];
int pre[1005][1005];

int event[1005][2];
int n, w;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> w;
    w += 2;
    
    for (int i = 3; i <= w; i++){
        cin >> event[i][0] >> event[i][1];
    }
    
    event[1][0] = 1;
    event[1][1] = 1;
    event[2][0] = n;
    event[2][1] = n;
    
    for (int i = 1; i <= w; i++){
        for (int j = i; j <= w; j++){
            dist[i][j] = abs(event[i][0] - event[j][0]) + abs(event[i][1] - event[j][1]);
            dist[j][i] = dist[i][j];
            
            dp[i][j] = dp[j][i] = 1000000;
        }
    }
    
    dp[1][2] = 0;
    
    for (int i = 3; i <= w; i++){
        for (int j = 1; j < i-1; j++){
            if (j != 2){
                if (dp[i][i-1] > dp[j][i-1] + dist[j][i]){
                    dp[i][i-1] = dp[j][i-1] + dist[j][i];
                    pre[i][i-1] = j;
                }
                
                dp[j][i] = dp[j][i-1] + dist[i-1][i];
                pre[j][i] = i-1;
            }

            if (j != 1){
                if (dp[i-1][i] > dp[i-1][j] + dist[j][i]){
                    dp[i-1][i] = dp[i-1][j] + dist[j][i];
                    pre[i-1][i] = j;
                }
                
                dp[i][j] = dp[i-1][j] + dist[i-1][i];
                pre[i][j] = i-1;    
            }
        }
    }
    
    int ans = 1000000;
    int x, y;
    for (int i = 3; i <= w; i++){
        if (dp[w][i] < ans){
            ans = dp[w][i];
            x = w;
            y = i;
        }
        if (dp[i][w] < ans){
            ans = dp[i][w];
            x = i;
            y = w;
        }
    }
    
    cout << ans << endl;
    
    stack<int> s;
    
    for (int i = 3; i <= w; i++){
        int pre_id = pre[x][y];
        
        if (x > y){
            x = pre_id;
            s.push(1);
        } else {
            y = pre_id;
            s.push(2);
        }
    }
    
    while (!s.empty()){
        cout << s.top() << endl;
        s.pop();
    }
    
    return 0;
}