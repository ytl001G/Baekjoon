#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll s[1000001];
ll num[1000001];
ll mods[1001];
ll n, m;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    // mods[0] = 1;
    for(ll i = 1; i <= n; i++){
        cin >> num[i];
        s[i] = (s[i-1] + num[i]) % m;
        mods[s[i]]++;
    }
    
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        ans += mods[s[i]]-1;
    }
    
    cout << ans/2+mods[0];

    return 0;
}
