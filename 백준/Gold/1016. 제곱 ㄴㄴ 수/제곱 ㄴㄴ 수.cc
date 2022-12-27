#include <bits/stdc++.h>
#include <vector>

#define FASTIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long int
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define FORR(i, a, b) for (int i = b-1; i > a-1; i--)
#define endl "\n"

using namespace std;

ll sieve[1000000] = {0,};
ll anssieve[1000001] = {0,};

int main() {
    FASTIO;

    ll n, m;
    cin >> n;
    cin >> m;

    for (ll i = 2; i*i <= m; i++)
    {
        if (sieve[i] == 0){
            for (ll j = i*2; j*j <= m; j += i)
            {
                sieve[j] = 1;
            }

            for (ll j = n/(i*i); j <= m/(i*i); j++)
            {  
                ll id = j*i*i;
                if (id < n || m < id) continue;

                anssieve[id-n] = 1;
            }
        }
    }

    ll ans = 0;
    FOR(i,0,m-n+1){
        ans += anssieve[i];
    }
    cout << (m-n+1) - ans;

    return 0;
}