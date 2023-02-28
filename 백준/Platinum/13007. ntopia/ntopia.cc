#include <bits/stdc++.h>
using namespace std;

const long long int mod = 1000000007LL;
long long int fact[1000001];
long long int fact_inv[1000001];

long long int comb(int n, int k){
    if (n < 0 || k > n) return 0;
    long long int ans = fact[n];
    ans = ans * fact_inv[k] % mod;
    ans = ans * fact_inv[n-k] % mod;
    
    return ans;
}

long long int poow(int x, int y){
    long long int ans = 1;
    long long int temp = x;
    while (y){
        if (y & 1){
            ans *= temp;
            ans %= mod;
        }

        y >>= 1;
        temp *= temp;
        temp %= mod;
    }
    
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int s, a, b, c;
    cin >> s >> a >> b >> c;
    
    fact[0] = 1;
    for (int i = 1; i <= s; i++){
        fact[i] = fact[i-1] * i;
        fact[i] %= mod;
    }
    
    fact_inv[0] = 1;
    for (int i = 1; i <= s; i++){
        fact_inv[i] = fact_inv[i-1] * poow(i, mod-2);
        fact_inv[i] %= mod;
    }
    
    long long int ans = 0;
    int sign = 1;
    for (int i = 0; i <= s; i++){
        long long int temp = comb(s, i);
        temp = temp * comb(s-i, a) % mod;
        temp = temp * comb(s-i, b) % mod;
        temp = temp * comb(s-i, c) % mod;
        
        ans += sign * temp;
        ans %= mod;
        ans = (ans + mod) % mod;
        
        sign = -sign;
    }
    
    cout << ans;

    return 0;
}
