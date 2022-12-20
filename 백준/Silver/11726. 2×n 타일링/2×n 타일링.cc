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

    int tile[1001];
    tile[1] = 1;
    tile[2] = 2;

    iin(n);

    FOR(i,3,n+1){
        tile[i] = tile[i-1] + tile[i-2];
        tile[i] %= 10007;
    }

    cout << tile[n];

    return 0;
}