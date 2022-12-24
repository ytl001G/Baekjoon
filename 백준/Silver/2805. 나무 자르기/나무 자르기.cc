#include <bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long int
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define FORR(i, a, b) for (int i = b-1; i > a-1; i--)
#define iin(i) int i; cin >> i;
#define endl "\n"

using namespace std;

int main() {
    FASTIO;

    iin(n);
    iin(m);

    int *trees = new int[n];

    int mlen = 0;
    FOR(i,0,n){
        cin >> trees[i];
        mlen = max(mlen,trees[i]);
    }

    ll s = 0;
    ll e = mlen-1;
    ll mid;
    ll ans = 0;

    while(s<=e){
        mid = (s+e)/2;

        ll cnt = 0;
        FOR(i,0,n){
            if (trees[i]-mid > 0){
                cnt += trees[i]-mid;
            }
        }

        if (cnt >= m){
            s = mid+1;
            ans = mid;
        }else{
            e = mid-1;
        }
    }
    
    cout << ans;

    return 0;
}