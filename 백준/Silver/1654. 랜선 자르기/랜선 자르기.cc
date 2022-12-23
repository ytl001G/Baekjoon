#include <iostream>

#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long int
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define FORR(i, a, b) for (int i = b-1; i > a-1; i--)
#define iin(i) int i; cin >> i;
#define loop(n) FOR(i,0,n)

using namespace std;

int main() {
    FASTIO;

    iin(k);
    iin(n);

    ll *cable = new ll[k];
    ll M = 0;
    FOR(i,0,k){
        cin >> cable[i];
        if (cable[i] > M){
            M = cable[i];
        }
    }

    ll s = 1;
    ll e = M;
    ll ans = 0;

    while (s <= e){
        ll mid = (s+e)/2;

        ll cnt = 0;
        FOR(i,0,k){
            cnt += cable[i]/mid;
        }

        if (cnt >= n){
            s = mid+1;
            ans = mid;
        } else {
            e = mid-1;
        }
    }
    
    cout << ans;

    return 0;
}