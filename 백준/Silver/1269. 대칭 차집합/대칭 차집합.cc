#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"
#define forr(n) for(int i = 0; i < n; i++)

set<int> A, B;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;

    forr(n){
        int x;
        cin >> x;
        A.insert(x);
    }

    forr(m){
        int x;
        cin >> x;
        B.insert(x);
    }
    
    int ans = 0;
    for (auto it = A.begin(); it != A.end(); it++){
        if (B.find(*it) == B.end()) ans++;
    }
    
    for (auto it = B.begin(); it != B.end(); it++){
        if (A.find(*it) == A.end()) ans++;
    }

    cout << ans;

    return 0;
}
