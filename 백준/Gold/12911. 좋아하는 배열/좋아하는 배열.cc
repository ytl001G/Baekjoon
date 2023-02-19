#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

long long int dp[11][100001];
long long int acc[11];
vector<int> divisors[100001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    for (int i = 1; i <= m; i++){
        for (int j = i*2; j <= m; j+=i){
            divisors[j].push_back(i);
        }
    }
    
    for (int i = 1; i <= m; i++){
        dp[1][i] = 1;
        acc[1] += 1;
    }
    
    for (int i = 2; i <= n; i++){
        for (int j = 1; j <= m; j++){
            dp[i][j] += acc[i-1];
            for (int d : divisors[j]){
                dp[i][j] -= dp[i-1][d];
                dp[i][j] %= 1000000007LL;
                dp[i][j] += 1000000007LL;
                dp[i][j] %= 1000000007LL;
            }
            
            acc[i] += dp[i][j];
            acc[i] %= 1000000007LL;
        }
    }
    
    cout << acc[n];
    
    return 0;
}
