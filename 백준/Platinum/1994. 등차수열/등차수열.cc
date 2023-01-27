#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int n, ans;
int dp[2000][2000], A[2000];

/*
dp[i][j] : A[j] - A[i]를 공차로 하는 가장 긴 등차수열 길이
dp[i][j] = dp[j][next] + 1 (공차 같은 next있을 시) 없을시 2
*/

void memo(int i, int j){
    if(dp[i][j] || i >= j){
        return;
    }

    int d = A[j] - A[i];
    int p = lower_bound(A, A + n-1, A[j] + d) - A;

    // printf("i: %d, j: %d, p: %d, d: %d\n", i, j, p, d);
    // printf("%d %d %d\n", A[i], A[j], A[p]);

    if(A[p] == A[j]+d && p < n){
        memo(j,p);
        dp[i][j] = dp[j][p] + 1;
    } else{
        dp[i][j] = 2;
    }

    ans = max(dp[i][j], ans);
}

int main(){    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> A[i];
    }

    sort(A, A+n);

    int temp = 0;
    for (int i = 0; i < n; i++){
        temp++;
        ans = max(ans, temp);

        if(i == n-1 || A[i] != A[i+1]){
            temp = 0;
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            memo(i,j);
        }
    }

    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << ans;

    return 0;
}