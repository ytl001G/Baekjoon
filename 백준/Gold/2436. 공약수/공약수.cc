#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define forr(i, n) for(int i = 0; i < n; i++)

ll gcd(ll a, ll b){
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    ll g, l;
    cin >> g >> l;
    
    ll temp = (ll)floor(pow(g*l, 0.5));
    
    ll min = 987654321;
    ll mina, minb;
    for (int i = g; i <= temp; i += g){
        if ((g * l) % i == 0 && g * l / i + i < min && gcd(g * l / i, i) == g){
            min = g * l / i + i;
            mina = i;
            minb = g * l / i;
        }
    }

    cout << mina << " " << minb;
    
    return 0;
}
