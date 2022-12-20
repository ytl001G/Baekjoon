#include <iostream>
#include <algorithm>

#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long int
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define FORR(i, a, b) for (int i = b-1; i > a-1; i--)
#define iin(i) int i; cin >> i;
#define loop(n) int x = n; while(x--)

using namespace std;

int main() {
    FASTIO;

    iin(n);

    if (n <= 5) {
        if (n==3) cout << 1;
        else if (n==5) cout << 1;
        else cout << -1;

        return 0;
    }

    int *memo = new int[n+1];

    FOR(i,0,6){
        memo[i] = -1;
    }

    memo[3] = 1;
    memo[5] = 1;

    FOR(i, 6, n+1) {
        if (memo[i-5] != -1) memo[i] = memo[i-5]+1;
        else if (memo[i-3] != -1) memo[i] = memo[i-3]+1;
        else if (memo[i-5] != -1 && (memo[i-3] != -1)) memo[i] = min(memo[i-3], memo[i-5]) + 1;
        else memo[i] = -1;
    }

    cout << memo[n];

    return 0;
}