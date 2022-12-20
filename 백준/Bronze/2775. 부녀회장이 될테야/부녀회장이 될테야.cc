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

    int house[15][15];

    FOR(i,1,15)
        house[0][i] = i;

    
    FOR(i,1,15){
        FOR(j,1,15){
            if (j==1) house[i][j] = house[i-1][j];
            else {
                house[i][j] = house[i-1][j] + house[i][j-1];
            }
        }
    }

    iin(T);
    loop(T){
        iin(k);iin(n);

        cout << house[k][n] << "\n";
    }
    return 0;
}